<?php

function myFunction ($x, $y) {

    $noBlankLine = 1;
}

class MyClass
{

    use \MyTrait;
}

abstract class MyClassB {}

abstract class MyClassC
{

    public function noBlankLine() {

        $noBlankLine = 1;
    }

    abstract protected function noBlankLineProtected();
}

interface MyInterface;

interface MyInterfaceB
{

    public function method();
}

trait MyTrait
{

    use AnotherTrait;
}

trait MyTraitB
{

    private function noBlankLine($x)
    {

        $noBlankLine = function () use ($x) {

            $noBlankLine = 1;
        };
    }
}

$closure = function () {

    $noBlankLine = 1;
};