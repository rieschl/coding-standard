<?php

namespace WebimpressCodingStandardTest\Sniffs\PHP;

use Arrayobject;
use Datetime;
use InvalidArgumentexception;
use Runtimeexception;
use Some\BarClass;
use Some\FooClass as Foo;
use Some\MyTrait;
use WebimpressCodingStandardTest\Sniffs\AbstractTestCase;

class MyClass
    extends AbstractTestcase
    implements
        \PHP_codesniffer\sniffs\sniff,
        Arrayobject
{
    use \TestTrait;
    use Mytrait;

    public function method()
    {
        $dt = new Datetime();
        $ao = new arrayobject();
        $ai = new \Arrayiterator();
        $dr = \DATETIME
            ::
            createFromFormat('Y-m-d', '2015-12-16');
        $dx = \Datetime::createFromFormat('Y', '2016');

        $class = foo::class;

        $instance = new $class;
        $myConst = $class::CONSTANT;

        throw new Runtimeexception;

        new barclass();

        $dt = new
        \DatEtimE;
    }

    public function throwEx()
    {
        throw new Invalidargumentexception;
    }

    public function fromNamespace($foo)
    {
        $closure = function () use ($foo) {};

        return new CorrectclassnamecaseUnitTest();
    }

    public function method2(
        datetime $a,
        correctclassnamecaseunittest $b
    ) : datEtimE {
        /**
         * @param Arrayobject $ao
         * @return \arrayiterator
         */
        $f = function(arrayobject $ao) : \arrayiterator {
        };
    }

    /**
     * @see https://webimpress.com/
     * @param int $a
     * @param array|\TraverSable|\ArRAyObJeCt $b
     * @param callable $c
     * @param abstractTestCase|CorrectclassnamecaseUnitTest|null $testCase
     * @return \WebimpressCodingStandardtest\sniffs\abstracttestcase
     * @throws \Rangeexception
     */
    public function method3(
        int $a,
        $b,
        callable $c,
        abstracttestcase $testCase = null
    ) : \WebimpressCodingStandardtest\sniffs\abstracttestcase {
        throw new \RangeException;
    }

    /**
     * @param iterable|\traversable[]|\arrayobject[]|foo[] $a
     */
    public function trav(iterable $a)
    {
    }

    /**
     * @param \Bar[]\Foo[] $param
     */
    abstract public function invalidTypeFormatIsNotChanged($param);

    public function fnClosure()
    {
        $fn = fn(datetime $d) : datetime => $d;
    }
}
