## 题目

假设你正在爬楼梯。需要 n 步你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

```
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 步 + 1 步
2.  2 步
```

示例 2：

```
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 步 + 1 步 + 1 步
2.  1 步 + 2 步
3.  2 步 + 1 步
```

## 解答

假设n级楼梯有f(n)种爬法，因为第一次可以选择爬1步或者爬2步，因此：

* 如果第一次爬1步，那么剩下n-1级楼梯有f(n-1)种爬法
* 如果第一次爬2步，那么剩下n-2级楼梯有f(n-2)种爬法

故：f(n) = f(n - 1) + f(n - 2)

```c++
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0)  return 0;
        if(n == 1)  return 1;
        if(n == 2)  return 2;
        
        int count1 = 1,count2 = 2,count;   
        for(int i = 3;i <= n;i++){
            count = count1 + count2;
            count1 = count2;
            count2 = count;
        }
        
        return count;
    }
};
```
