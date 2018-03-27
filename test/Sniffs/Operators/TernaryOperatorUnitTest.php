<?php

declare(strict_types=1);

namespace ZendCodingStandardTest\Sniffs\Operators;

use ZendCodingStandardTest\Sniffs\TestCase;

class TernaryOperatorUnitTest extends TestCase
{
    public function getErrorList(string $testFile = '') : array
    {
        return [
            3 => 1,
            7 => 1,
            9 => 1,
            12 => 1,
            16 => 1,
            19 => 1,
            24 => 1,
            31 => 1,
            35 => 1,
            37 => 1,
        ];
    }

    public function getWarningList(string $testFile = '') : array
    {
        return [];
    }
}
