## 题目

实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

```
输入: 2.00000, 10
输出: 1024.00000
```

示例 2:

```
输入: 2.10000, 3
输出: 9.26100
```

示例 3:

```
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
```

说明:

* -100.0 < x < 100.0
* n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1]

## 解答

> * 当x为0时？
> * 当n为0时？
> * 当n为INT_MAX和**INT_MIN**时？

### 方法一

循环n次，每次乘以x

**时间复杂度**：O(n)

### 方法二

使用一个变量m表示指数，如果m\*2<n，则将结果平方，由于每次指数增长，所以比线性增长快很多

```c++
class Solution {
public:
    double myPow(double x, int n) {
        bool b = n < 0;
        
        if(x == 0)  return 0;
        if(n == 0)  return 1;
        
        //需要使用一个long long类型的变量，因为当n为INT_MIN时，和-1乘会溢出
        long long nl = n < 0 ? (long long)n * -1 : n;
        double ret = 1.0;
        
        while(nl){
            long long m = 1;//m必须也是long long,因为当m = INT_MAX/2+1时，计算m*2会溢出
            double tp = x;
            while(2 * m <= nl){
                tp *= tp;
                m *= 2;
            }
            nl = nl - m;
            ret *= tp;
        }
        
        ret = b ? 1 / ret : ret;
        return ret;
    }
};
```

**时间复杂度**：O(logn)

### 方法三

假设n为19(0010011)，那么求出x^1、x^2、x^16次方就行了:

```
res = x^1 * x^2 * x^16
```

res初始化为x^1，求出x^2和x^16时，再分别与res相乘

```c++
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)  return 0;
        if(n == 0)  return 1;
        
        long long nl = n;
        bool negative = nl < 0;
        if(negative)    nl = nl * -1;
        
        while((nl & 1) == 0){
            nl >>= 1;
            x *= x;
        }
        
        double res = x;
        nl >>= 1;
        
        while(nl){
            x *= x;
            if((nl & 1) == 1) res *= x;
            nl >>= 1;
        }
        
        if(negative)    return 1 / res;
        return res;
    }
};
```