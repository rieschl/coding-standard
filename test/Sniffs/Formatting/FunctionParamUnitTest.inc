<?php

$callback = function (
    string    $p1,
    int  & $p2,
    ?array  $p3,
    \A\B\C  $p4,
    array
        $p5
) {
};

function hello(string  $world, int  &$x = null) {}

function test(int$var,$bar,bool...$bools){}

function variableArgs(int   ...$ints) {}

static fn (?string  &$a) => $a;

function broken;
