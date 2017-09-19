<?php
namespace ZendCodingStandardTest\Sniffs\Functions;

use ZendCodingStandardTest\Sniffs\TestCase;

class ParamUnitTest extends TestCase
{
    /**
     * @param string $testFile
     * @return int[]
     */
    public function getErrorList($testFile = '')
    {
        return [
            18 => 1,
            20 => 1,
            23 => 1,
            33 => 1,
            37 => 1,
            40 => 1,
            50 => 3,
            54 => 1,
            57 => 1,
            67 => 1,
            72 => 1,
            77 => 1,
            81 => 1,
            83 => 1,
            85 => 3,
            93 => 1,
            98 => 1,
            103 => 1,
            108 => 1,
            110 => 1,
            113 => 1,
            115 => 1,
            118 => 1,
            123 => 1,
            125 => 1,
            128 => 1,
            129 => 1,
            131 => 1,
            134 => 1,
            138 => 2,
            140 => 2,
            143 => 1,
            144 => 1,
            149 => 1,
            154 => 1,
            155 => 2,
            160 => 1,
            161 => 1,
            162 => 1,
            163 => 1,
            164 => 1,
            165 => 1,
            166 => 1,
            167 => 1,
            172 => 1,
            173 => 1,
            176 => 1,
            177 => 1,
            181 => 1,
            185 => 1,
            188 => 1,
            192 => 1,
            195 => 1,
            200 => 1,
            201 => 1,
            203 => 2,
            207 => 1,
            212 => 1,
            213 => 1,
            214 => 1,
            219 => 1,
            220 => 1,
            221 => 1,
            226 => 1,
            227 => 1,
            232 => 1,
            233 => 1,
            234 => 1,
            235 => 1,
            245 => 1,
            246 => 1,
            247 => 1,
            252 => 1,
            254 => 1,
            255 => 1,
            256 => 1,
            257 => 1,
            271 => 1,
            272 => 1,
            273 => 1,
            282 => 1,
            296 => 1,
            301 => 1,
        ];
    }

    /**
     * @param string $testFile
     * @return int[]
     */
    public function getWarningList($testFile = '')
    {
        return [];
    }
}
