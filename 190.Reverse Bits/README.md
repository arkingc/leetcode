## 题目

颠倒给定的 32 位无符号整数的二进制位。

示例:

```
输入: 43261596
输出: 964176192
解释: 43261596 的二进制表示形式为 00000010100101000001111010011100 ，
     返回 964176192，其二进制表示形式为 00111001011110000010100101000000 。
```

进阶:

如果多次调用这个函数，你将如何优化你的算法？

## 解答

结果res初始化为1，假设n的第i比特为1，那么反转后res的第31-i比特为1。因此，如果从右往左处理，n的第i比特为1，因为n还剩31-i比特需要处理，那么每次将res左移1位，最终第31-i比特就是1：

```c++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int mask = 1;
        uint32_t res = 0;
        for(int i = 1;i <= 32;i++){
            res = (res << 1);
            if(n & mask)
                res |= 1;
            mask = mask << 1;
        }
        return res;
    }
};
```

Discuss里面的一种解答：

```c++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
```
