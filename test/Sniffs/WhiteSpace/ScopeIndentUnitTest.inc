<?php

class Test
{
    /**
     * @param mixed $a
     * @param mixed $b
     * @return int
     */
public function method($a, $b)
{
if ($a > $b) {
return 1;
}

return [
            1,
            2,
        ];
}
}

switch (true) {
case '1':
echo 1;
break;
case '2':
echo 2;
break;
default:
switch ($a) {
default:
case 0:
echo 9;
return 17;
case 1:
break;
}
break;
}

usort($a, function($x, $y) {
  return $x > $y;
});

function x($a) {
   /*
    * some comment
    */
    $y = $a;

    return $y;
}

class Test2 {
    public $var = <<<VAR
This is multiline
variable
content.
VAR;

    public $bar = <<<'BAR'
Another one.
BAR;

    public $foo = '
       multiline
            content
 here';
}

$var = ($a
? 'a'
: 'b') . 'x';

$bar = 'x' . ($b
        ? 'a'
        : 'b');

$foo = $a
    ? $b
    ? $c
    : $d
    : $e;

$variable->call($a, $b)
    ->another($x)
    ->oneMore($d);

(new DateTime())
      ->modify('-1 day')
      ->modify('-1 hour');

$m = (new DateTime())->modify('-1 second')
   ->modify('+1 second');

$val = $class->{$method}($value)
    ->{$value};

$v = $a->{$m}(1)
    ->{$d}
    ->date
    ->modify('-1 day')
    ->format('Y-m-d');

$f = function () use (
    $foo,
    $bar
) {
      return $foo + $bar;
};

LABEL:

    $something = 'porter';

OTHER:

  $other = 'label';

$g = $t->method()
       ->another(function () {
         $x = 13;

         return $x;
       });

$concatenation = 'string'
               . 'next part';

$sum = $a
     + $b;

class B {
    public function foo()
    {
        return function ($stream, $streamIndex) {
            return preg_match('#(.*?)\r?\n#', $stream, $matches, null, $streamIndex) === 1
                   ? $matches[1]
                   : substr($stream, $streamIndex);
        };
    }

    public function bar($parameters)
    {
        return array_filter(
            $parameters,
            function (array $parameter) {
                return PHP_VERSION_ID >= 70100
                    || (
                        false === strpos($parameter[2], '?')
                        && ! in_array(strtolower($parameter[2]), ['void', 'iterable'])
                );
            }
        );
    }

    public function tar($abc, $def)
    {
        /*
            this part is commented out
            and doesn't matter
        what
    indent
do we have here.

         */
        return PHP_VERSION_ID >= 70100 && (
                $abc
                || $def
        );
    }

    private function test2($services)
    {
        return function () use ($services) {
            return $services->get('Application')
                ->method1()
                ->method2();
        };
    }
}

switch ($a) {
   // POST
    case 'POST':
        $do = 'something';
        break;
        // GET
    case 'GET':
    // my comment here
        break;
// All others
    default:
        $do = 'nothing';
        break;
}

echo "This is a long
string that spans $numLines lines
      without indenting.
";

$oldArray = array(
 'the', 'sniff',
    'does',
   'check',      'indents', 'in',
  'arrays'
);

class Test3
{
    public static $a;

    public static function xyz($b)
    {
        if (static::$a[$b] === null) {
            static::$a[$b] = new static(
                  'it',
                 'is',
                      'not checked in that sniff'
            );
        }
    }
}

$obj->{$m}(
  'skip',
    'it'
);

if ($a == 5) :
  echo "a equals 5";
    echo "...";
elseif ($a == 6) :
    echo "a equals 6";
  echo "!!!";
else :
      echo "a is neither 5 nor 6";
endif;

if ($foo):
    if ($bar) $foo = 1;
      elseif ($baz) $foo = 2;
endif;

usort(
    $a,
    function (
         $x,
        $y
    ) {
    return $x > $y;
    }
);

$var = $foo
    && $bar
    && ($baz
    || $key);

$num = $multi
    * ($val1
    + $val2)
    + $int;

$closure = function (
    $a,
     $b,
    $c
) {
    if ($a + $b > $c) {
        return $a
            && ($b
                || $c);
    }

    return $b && ($a
            || $c);
};

switch ($r) {
case self::TYPE:
$var = null;
if ($x) {
 return 1;
}
exit;
case self::GO;
return function () use ($r) {
if ($r) {
throw new \InvalidArgumentException(
sprintf('Error %s', 'value')
);
}

return function ($a, $b) {
return $a <=> $b;
};
};
case self::DEF:
 default:
$var = 1;
throw new \Exception(sprintf(
'Type "%s" is unknown or cannot be used as property default value.',
get_class($value)
));
}

(function ($a, $b) {
return function ($c, $d) use ($a, $b) {
echo $a, $b, $c, $d;
};
})(
 'a',
'b'
)(
 'c',
'd'
);

(new \DateTime([
    'something',
]))->format('ymd');

$myVariable
    ->call(sprintf(
        'Text %s',
        'value'
    ));

class MyClass
{
    public function test()
    {
    }
}

$mock->expects(
    $this->any()
)
->method('get')
->will($this->throwException());

$mock->expects($this->any())
->method(
'get'
)
->will($this->throwException());

$mock
->expects($this->any())
->method(
'get'
)
->will($this->throwException());

$mock
->expects(
$this->any()
)
->method('get')
->will($this->throwException());

class Test3
{
    public function method()
    {
        $mock->expects(
            $this->any()
        )
            ->method('get')
            ->will($this->throwException());

        $mock->expects($this->any())
            ->method(
                'get'
            )
            ->will($this->throwException());

        $mock
            ->expects($this->any())
            ->method(
                'get'
            )
            ->will($this->throwException());

        $mock
            ->expects(
                $this->any()
            )
            ->method('get')
            ->will($this->throwException());
    }

    public function method2()
    {
        $mock->method(
            'param'
        )->shouldBeCalled();
    }

public function method3()
{
$list = [
'fn' => function ($a) {
if ($a === true) {
echo 'hi';
}
},
'call' => sprintf(
'Text %s',
'param'
),
];
}
}