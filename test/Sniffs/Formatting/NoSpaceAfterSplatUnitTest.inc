<?php

function method($a, $b, ... $c) {
    if ($a < $b) {
        method(... func_get_args());
    }
}

class MyClass
{
    public function method($foo, ... $bar)
    {
        method($foo, 0, ... $bar);
    }
}

method(...$_GET);
method(.../*comment*/$_POST);
