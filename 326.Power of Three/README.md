## 题目

给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:

```
输入: 27
输出: true
```

示例 2:

```
输入: 0
输出: false
```

示例 3:

```
输入: 9
输出: true
```

示例 4:

```
输入: 45
输出: false
```

进阶：

你能不使用循环或者递归来完成本题吗？

## 解答

### 方法一：递归

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)  return false;
        if(n == 1)  return true;
        if(n % 3 != 0)  return false;
        return isPowerOfThree(n/3);
    }
};
```

### 方法二：迭代

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 0)  return false;
        
        while(n){
            if(n == 1)  return true;
            if(n % 3 != 0)  return false;
            n /= 3;
        }
        
        return false;
    }
};
```

### 方法三：Discuss中不使用递归和迭代的方法

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1162261467 is 3^19,  3^20 is bigger than int  
        return ( n>0 &&  1162261467%n==0);
    }
};

//下列函数可以用以获取int中最大的3的幂的数
int getMaxPowerOfThree() {
    int max = 1;
    while (max * 3 > max) max *= 3;
    return max;
}
```