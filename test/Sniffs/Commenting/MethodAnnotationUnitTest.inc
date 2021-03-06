<?php
// @phpcs:set WebimpressCodingStandard.Commenting.MethodAnnotation allowedAnnotations[]

abstract class MethodCommentWithoutAnnotations
{
    /**
     * @return string
     * @ORM\Annotation
     * @Annotation\Hello
     */
    public function foo() : string
    {
        return 'string';
    }

    /**
     * @return void
     * @ORM\JoinColumn({
     *     @ORM\Something,
     *     @Rbac(entity=Some)
     * })
     */
    abstract protected function bar() : void;

    /**
     * @var bool
     * @ORM\Column(@ORM\Value({"var", "bar", "baz"}))
     */
    private static function baz() : void
    {
    }

    /**
     * @ORM\FinalMethod
     * @Config(key="value")
     */
    final public function finalMethod()
    {
        return __CLASS__;
    }
}

new class ()
{
    /**
     * @ThisIsNotParsedAsItIsMethodOfAnonymousClass
     */
    public function withAnnotations() : void
    {
    }
};
