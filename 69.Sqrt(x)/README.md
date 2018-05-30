## 题目

实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

```
输入: 4
输出: 2
```

示例 2:

```
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
```

## 解答

在INT范围内进行二分查找

需要特别注意的是，如果使用res * res 与 x进行比较，那么res * res可能会溢出

```c++
class Solution {
public:
    int mySqrt(int x) {
        if(x < 0 || x == 0)   return 0;
        
        int l = 1,r = INT_MAX;
        while(true){
            int mid = l + ((r - l) >> 1);
            if(mid > x / mid)  //mid * mid > x，继续往左边找
                r = mid - 1;
            else{ //mid * mid <= x
                if(mid + 1 > x / (mid + 1)) 
                    return mid;
                l = mid + 1;
            }
        }
    }
};
```