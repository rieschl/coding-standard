<?php

namespace MyNamespace\Test\Functions;

use DateTime as DT;
use MyNamespace\FunctionCommentReturnParent as ParentClass;

abstract class FunctionCommentReturn extends ParentClass
{
    abstract public function classNameReturnTypeShouldBeSelfInstead() : FunctionCommentReturn;

    abstract public function nullableClassNameReturnTypeShouldBeSelfInstead() : ?FunctionCommentReturn;

    abstract public function fcqnClassNameReturnTypeShouldBeSelfInstead()
    : \MyNamespace\Test\Functions\FunctionCommentReturn;

    abstract public function fcqnNullableClassNameReturnTypeShouldBeSelfInstead()
    : ?\MyNamespace\Test\Functions\FunctionCommentReturn;

    abstract public function parentClassNameReturnTypeShouldBeParentInstead() : ParentClass;

    abstract public function nullableParentClassNameReturnTypeShouldBeParentInstead() : ?ParentClass;

    abstract public function fcqnParentClassNameReturnTypeShouldBeParentInstead()
    : \MyNamespace\FunctionCommentReturnParent;

    abstract public function fcqnNullableParentClassNameReturnTypeShouldBeParentInstead()
    : ?\MyNamespace\FunctionCommentReturnParent;

    abstract public function returnTypeInvalidPrimitiveTypeCase() : Int;

    abstract public function returnTypeInvalidComplexTypeCase() : dt;

    abstract public function returnTypeCanUseAliasInsteadOfFCQN() : \DateTime;

    /**
     * @return \ArrayAccess
     */
    abstract public function missingNullableInTag() : ?\ArrayObject;

    /**
     * @return null|\ArrayAccess
     */
    abstract public function missingNullableInReturnType() : \ArrayObject;

    /**
     * @return DT
     */
    abstract public function redundantTag1() : DT;

    /**
     * @return null|DT
     */
    abstract public function redundantTag2() : ?DT;

    /**
     * @return parent
     */
    abstract public function returnParent1() : parent;

    /**
     * @return null|parent
     */
    abstract public function returnParent2() : parent;

    /**
     * @return parent|null
     */
    abstract public function returnParent3() : parent;

    /**
     * @return self
     */
    abstract public function returnParent4() : parent;

    /**
     * @return null|self
     */
    abstract public function returnParent5() : parent;

    /**
     * @return self|null
     */
    abstract public function returnParent6() : parent;

    /**
     * @return static
     */
    abstract public function returnParent7() : parent;

    /**
     * @return null|static
     */
    abstract public function returnParent8() : parent;

    /**
     * @return static|null
     */
    abstract public function returnParent9() : parent;

    /**
     * @return $this
     */
    abstract public function returnParent10() : parent;

    /**
     * @return null|$this
     */
    abstract public function returnParent11() : parent;

    /**
     * @return $this|null
     */
    abstract public function returnParent12() : parent;

    /**
     * @return SomethingElse
     */
    abstract public function returnParent13() : parent;

    /**
     * @return null|SomethingElse
     */
    abstract public function returnParent14() : parent;

    /**
     * @return SomethingElse|null
     */
    abstract public function returnParent15() : parent;

    /**
     * @return AnotherClass
     */
    abstract public function returnParent16() : Parent;

    /**
     * @return parent
     */
    abstract public function returnNullableParent1() : ?parent;

    /**
     * @return null|parent
     */
    abstract public function returnNullableParent2() : ?parent;

    /**
     * @return parent|null
     */
    abstract public function returnNullableParent3() : ?parent;

    /**
     * @return self
     */
    abstract public function returnNullableParent4() : ?parent;

    /**
     * @return null|self
     */
    abstract public function returnNullableParent5() : ?parent;

    /**
     * @return self|null
     */
    abstract public function returnNullableParent6() : ?parent;

    /**
     * @return static
     */
    abstract public function returnNullableParent7() : ?parent;

    /**
     * @return null|static
     */
    abstract public function returnNullableParent8() : ?parent;

    /**
     * @return static|null
     */
    abstract public function returnNullableParent9() : ?parent;

    /**
     * @return $this
     */
    abstract public function returnNullableParent10() : ?parent;

    /**
     * @return null|$this
     */
    abstract public function returnNullableParent11() : ?parent;

    /**
     * @return $this|null
     */
    abstract public function returnNullableParent12() : ?parent;

    /**
     * @return SomethingElse
     */
    abstract public function returnNullableParent13() : ?parent;

    /**
     * @return null|SomethingElse
     */
    abstract public function returnNullableParent14() : ?parent;

    /**
     * @return SomethingElse|null
     */
    abstract public function returnNullableParent15() : ?parent;

    /**
     * @return AnotherClass
     */
    abstract public function returnNullableParent16() : ?Parent;

    /**
     * @return self
     */
    abstract public function returnSelf1() : self;

    /**
     * @return null|self
     */
    abstract public function returnSelf2() : self;

    /**
     * @return self|null
     */
    abstract public function returnSelf3() : self;

    /**
     * @return static
     */
    abstract public function returnSelf4() : self;

    /**
     * @return null|static
     */
    abstract public function returnSelf5() : self;

    /**
     * @return static|null
     */
    abstract public function returnSelf6() : self;

    /**
     * @return $this
     */
    abstract public function returnSelf7() : self;

    /**
     * @return null|$this
     */
    abstract public function returnSelf8() : self;

    /**
     * @return $this|null
     */
    abstract public function returnSelf9() : self;

    /**
     * @return SomeClass
     */
    abstract public function returnSelf10() : self;

    /**
     * @return null|SomeClass
     */
    abstract public function returnSelf11() : self;

    /**
     * @return SomeClass|null
     */
    abstract public function returnSelf12() : self;

    /**
     * @return AnotherClass
     */
    abstract public function returnSelf13() : Self;

    /**
     * @return string|SomeClass
     */
    abstract public function returnTypeComplexTagWithPrimitive1() : SomeClass;

    /**
     * @return bool|int[]|SomeClass
     */
    abstract public function returnTypeComplexTagWithPrimitive2() : SomeClass;

    /**
     * @return string
     */
    abstract public function returnTypePrimitiveDoesNotMatchWithTag1() : int;

    /**
     * @return int|string
     */
    abstract public function returnTypePrimitiveDoesNotMatchWithTag2() : string;
}

interface MyInterface extends MyOne, MyTwo
{
    public function method1($self) : MyInterface;

    public function method2($myOne) : MyOne;

    public function method3($myTwo) : MyTwo;

    /**
     * @return array|int[]
     */
    public function typeCannotBeDuplicatedArray() : array;

    /**
     * @return iterable|int[]
     */
    public function typeCannotBeDuplicatedIterable() : iterable;

    /**
     * @return \Traversable|int[]
     */
    public function typeCannotBeDuplicatedTraversable() : \Traversable;

    /**
     * @return \Generator|int[]
     */
    public function typeCannotBeDuplicatedGenerator() : \Generator;

    /**
     * @return object|Foo
     */
    public function typeCannotBeDuplicatedObject() : object;

    /**
     * @return null|array Description
     */
    public function typeWithDescriptionArray() : ?array;

    /**
     * @return null|iterable Description
     */
    public function typeWithDescriptionIterable() : ?iterable;

    /**
     * @return null|\Traversable Description
     */
    public function typeWithDescriptionTraversable() : ?\Traversable;

    /**
     * @return null|\Generator Description
     */
    public function typeWithDescriptionGenerator() : ?\Generator;

    /**
     * @return null|object Description
     */
    public function typeWithDescriptionObject() : ?object;

    /**
     * @return null|int[]|array Description
     */
    public function typeSpecifiedWithDescriptionArray() : ?array;

    /**
     * @return null|int[]|iterable Description
     */
    public function typeSpecifiedWithDescriptionIterable() : ?iterable;

    /**
     * @return null|int[]|\Traversable Description
     */
    public function typeSpecifiedWithDescriptionTraversable() : ?\Traversable;

    /**
     * @return null|int[]|\Generator Description
     */
    public function typeSpecifiedWithDescriptionGenerator() : ?\Generator;

    /**
     * @return null|Foo|object Description
     */
    public function typeSpecifiedWithDescriptionObject() : ?object;

    /**
     * @return      null|int
     */
    public function moreThanOneSpace() : ?int;
}
