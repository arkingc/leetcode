## 题目

给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:

```
输入: 123
输出: 321
```

示例 2:

```
输入: -123
输出: -321
```

示例 3:

```
输入: 120
输出: 21
```

注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0

## 解答

每计算一次结果先乘以10，每次对10取模，加入结果中。注意溢出

```c++
class Solution {
public:
    int reverse(int x) {
        long long res = 0,num = x;
        bool negative = (num < 0);
        if(negative)    num *= -1;
        while(num){
            res = res * 10 + (num % 10);
            num = num / 10;
            if(res > INT_MAX){
                if(!negative)   return 0;
                if(res - 1 > INT_MAX)   return 0;
            }
        }
        if(negative)    res *= -1;
        return res;
    }
};
```