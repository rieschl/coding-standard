<?php

declare(strict_types=1);

namespace WebimpressCodingStandard\Sniffs\PHP;

use PHP_CodeSniffer\Files\File;
use PHP_CodeSniffer\Sniffs\Sniff;
use PHP_CodeSniffer\Util\Tokens;
use WebimpressCodingStandard\CodingStandard;
use WebimpressCodingStandard\Helper\NamespacesTrait;
use WebimpressCodingStandard\Sniffs\Namespaces\UnusedUseStatementSniff;

use function array_flip;
use function get_defined_functions;
use function in_array;
use function ltrim;
use function sprintf;
use function strtolower;

use const T_AS;
use const T_BITWISE_AND;
use const T_DOUBLE_COLON;
use const T_FUNCTION;
use const T_NAMESPACE;
use const T_NEW;
use const T_NS_SEPARATOR;
use const T_OBJECT_OPERATOR;
use const T_OPEN_PARENTHESIS;
use const T_SEMICOLON;
use const T_STRING;
use const T_USE;
use const T_WHITESPACE;

class ImportInternalFunctionSniff implements Sniff
{
    use NamespacesTrait;

    /**
     * @var string[] Array of functions to exclude from importing.
     */
    public $exclude = [];

    /**
     * @var array Hash map of all php built in function names.
     */
    private $builtInFunctions;

    /**
     * @var File Currently processed file.
     */
    private $currentFile;

    /**
     * @var string Currently processed namespace.
     */
    private $currentNamespace;

    /**
     * @var array Array of imported function in current namespace.
     */
    private $importedFunctions;

    /**
     * @var null|int Last use statement position.
     */
    private $lastUse;

    public function __construct()
    {
        $allFunctions = get_defined_functions();
        $this->builtInFunctions = array_flip($allFunctions['internal']);
    }

    /**
     * @return int[]
     */
    public function register() : array
    {
        return [T_STRING];
    }

    /**
     * @param int $stackPtr
     */
    public function process(File $phpcsFile, $stackPtr)
    {
        if ($this->currentFile !== $phpcsFile) {
            $this->currentFile = $phpcsFile;
            $this->currentNamespace = null;
        }

        $tokens = $phpcsFile->getTokens();

        $namespace = $this->getNamespace($phpcsFile, $stackPtr);
        if ($namespace && $this->currentNamespace !== $namespace) {
            $this->currentNamespace = $namespace;
            $this->importedFunctions = $this->getImportedFunctions($phpcsFile, $stackPtr, $this->lastUse);

            foreach ($this->importedFunctions as $func) {
                $fqn = strtolower($func['fqn']);

                if (in_array($fqn, $this->exclude, true)) {
                    $error = 'Function %s cannot be imported';
                    $data = [$func['fqn']];
                    $fix = $phpcsFile->addFixableError($error, $func['ptr'], 'ExcludeImported', $data);

                    if ($fix) {
                        $phpcsFile->fixer->beginChangeset();
                        for ($i = $func['ptr']; $i <= $func['eos']; ++$i) {
                            $phpcsFile->fixer->replaceToken($i, '');
                        }
                        if ($tokens[$i + 1]['code'] === T_WHITESPACE) {
                            $phpcsFile->fixer->replaceToken($i + 1, '');
                        }
                        $phpcsFile->fixer->endChangeset();
                    }
                }
            }
        }

        // Make sure this is a function call.
        $next = $phpcsFile->findNext(Tokens::$emptyTokens, $stackPtr + 1, null, true);
        if (! $next || $tokens[$next]['code'] !== T_OPEN_PARENTHESIS) {
            return;
        }

        $content = strtolower($tokens[$stackPtr]['content']);
        if (! isset($this->builtInFunctions[$content])) {
            return;
        }

        $prev = $phpcsFile->findPrevious(
            Tokens::$emptyTokens + [T_BITWISE_AND => T_BITWISE_AND, T_NS_SEPARATOR => T_NS_SEPARATOR],
            $stackPtr - 1,
            null,
            true
        );
        if ($tokens[$prev]['code'] === T_FUNCTION
            || $tokens[$prev]['code'] === T_NEW
            || $tokens[$prev]['code'] === T_STRING
            || $tokens[$prev]['code'] === T_DOUBLE_COLON
            || $tokens[$prev]['code'] === T_OBJECT_OPERATOR
        ) {
            return;
        }

        $prev = $phpcsFile->findPrevious(Tokens::$emptyTokens, $stackPtr - 1, null, true);
        if ($tokens[$prev]['code'] === T_NS_SEPARATOR) {
            if (! $namespace) {
                $error = 'FQN for PHP internal function "%s" is not needed here, file does not have defined namespace';
                $data = [
                    $content,
                ];

                $fix = $phpcsFile->addFixableError($error, $stackPtr, 'NoNamespace', $data);
                if ($fix) {
                    $phpcsFile->fixer->replaceToken($prev, '');
                }
            } elseif (in_array($content, $this->exclude, true)) {
                $error = 'FQN for PHP internal function "%s" is not allowed here';
                $data = [
                    $content,
                ];

                $fix = $phpcsFile->addFixableError($error, $stackPtr, 'ExcludeRedundantFQN', $data);
                if ($fix) {
                    $phpcsFile->fixer->replaceToken($prev, '');
                }
            } elseif (isset($this->importedFunctions[$content])) {
                if (strtolower($this->importedFunctions[$content]['fqn']) === $content) {
                    $error = 'FQN for PHP internal function "%s" is not needed here, function is already imported';
                    $data = [
                        $content,
                    ];

                    $fix = $phpcsFile->addFixableError($error, $stackPtr, 'RedundantFQN', $data);
                    if ($fix) {
                        $phpcsFile->fixer->replaceToken($prev, '');
                    }
                }
            } else {
                $error = 'PHP internal function "%s" must be imported';
                $data = [
                    $content,
                ];

                $fix = $phpcsFile->addFixableError($error, $stackPtr, 'ImportFQN', $data);
                if ($fix) {
                    $phpcsFile->fixer->beginChangeset();
                    $phpcsFile->fixer->replaceToken($prev, '');
                    $this->importFunction($phpcsFile, $stackPtr, $content);
                    $phpcsFile->fixer->endChangeset();
                }
            }
        } elseif ($namespace) {
            if (! isset($this->importedFunctions[$content])
                && ! in_array($content, $this->exclude, true)
            ) {
                $error = 'PHP internal function "%s" must be imported';
                $data = [
                    $content,
                ];

                $fix = $phpcsFile->addFixableError($error, $stackPtr, 'Import', $data);
                if ($fix) {
                    $phpcsFile->fixer->beginChangeset();
                    $this->importFunction($phpcsFile, $stackPtr, $content);
                    $phpcsFile->fixer->endChangeset();
                }
            }
        }
    }

    private function importFunction(File $phpcsFile, int $stackPtr, string $functionName) : void
    {
        if ($this->lastUse) {
            $ptr = $phpcsFile->findEndOfStatement($this->lastUse);
        } else {
            $nsStart = $phpcsFile->findPrevious(T_NAMESPACE, $stackPtr);
            $tokens = $phpcsFile->getTokens();
            if (isset($tokens[$nsStart]['scope_opener'])) {
                $ptr = $tokens[$nsStart]['scope_opener'];
            } else {
                $ptr = $phpcsFile->findEndOfStatement($nsStart);
                $phpcsFile->fixer->addNewline($ptr);
            }
        }

        $phpcsFile->fixer->addNewline($ptr);
        $phpcsFile->fixer->addContent($ptr, sprintf('use function %s;', $functionName));
        if (! $this->lastUse && (! $nsStart || isset($tokens[$nsStart]['scope_opener']))) {
            $phpcsFile->fixer->addNewline($ptr);
        }

        $this->importedFunctions[$functionName] = [
            'name' => $functionName,
            'fqn' => $functionName,
        ];
    }

    /**
     * @return array Array of imported functions {
     *     @var array $_ Key is lowercase function name {
     *         @var string $name Original function name
     *         @var string $fqn Fully qualified function name without leading slashes
     *         @var int $ptr The position of use declaration
     *         @var int $eos The position of the end of the use statement
     *     }
     * }
     */
    private function getImportedFunctions(File $phpcsFile, int $stackPtr, ?int &$lastUse) : array
    {
        $first = 0;
        $last = $phpcsFile->numTokens;

        $tokens = $phpcsFile->getTokens();

        $nsStart = $phpcsFile->findPrevious(T_NAMESPACE, $stackPtr);
        if ($nsStart && isset($tokens[$nsStart]['scope_opener'])) {
            $first = $tokens[$nsStart]['scope_opener'];
            $last = $tokens[$nsStart]['scope_closer'];
        }

        $lastUse = null;
        $functions = [];

        $use = $first;
        while ($use = $phpcsFile->findNext(T_USE, $use + 1, $last)) {
            if (! CodingStandard::isGlobalUse($phpcsFile, $use)) {
                continue;
            }

            // Check if the statement is not planned to be removed.
            if (isset($phpcsFile->getMetrics()[UnusedUseStatementSniff::class]['values'][$use])) {
                continue;
            }

            if ($next = $this->isFunctionUse($phpcsFile, $use)) {
                $start = $phpcsFile->findNext([T_STRING, T_NS_SEPARATOR], $next + 1);
                $end = $phpcsFile->findPrevious(
                    T_STRING,
                    $phpcsFile->findNext([T_AS, T_SEMICOLON], $start + 1) - 1
                );
                $endOfStatement = $phpcsFile->findEndOfStatement($next);
                $name = $phpcsFile->findPrevious(T_STRING, $endOfStatement - 1);
                $fullName = $phpcsFile->getTokensAsString($start, $end - $start + 1);

                $functions[strtolower($tokens[$name]['content'])] = [
                    'name' => $tokens[$name]['content'],
                    'fqn' => ltrim($fullName, '\\'),
                    'ptr' => $use,
                    'eos' => $endOfStatement,
                ];
            }

            $lastUse = $use;
        }

        return $functions;
    }

    /**
     * @return false|int
     */
    private function isFunctionUse(File $phpcsFile, int $stackPtr)
    {
        $tokens = $phpcsFile->getTokens();
        $next = $phpcsFile->findNext(Tokens::$emptyTokens, $stackPtr + 1, null, true);

        if ($tokens[$next]['code'] === T_STRING
            && strtolower($tokens[$next]['content']) === 'function'
        ) {
            return $next;
        }

        return false;
    }
}
