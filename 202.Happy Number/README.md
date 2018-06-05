## 题目

编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例: 

```
输入: 19
输出: true
解释: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
```

## 解答

### 方法一：利用辅助空间

可以使用一个set存储已经处理过的数，下一个数存在于set中，说明出现了重复，那么会进入无限循环，因此返回false：

```c++
class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0)   return false;
        if(n == 1)  return true;
        
        unordered_set<int> s;
        s.insert(n);
        
        int next = 0;
        while(n){
            int digit = n % 10;
            next += digit * digit;
            n = n /10;
            if(n == 0){
                if(next == 1)   return true;
                if(s.find(next) != s.end()) return false;
                s.insert(next);
                n = next;
                next = 0;
            }
        }
        
        return false;
    }
};
```

### 方法二：不需要辅助空间

1\~6中，只有1是“快乐数”，因此，计算直到下一个数落在1~6的范围内，然后如果是1就返回true，否则返回false：

```c++
class Solution {
public:
    bool isHappy(int n) {
        while(n>6){
            int next = 0;
            while(n){next+=(n%10)*(n%10); n/=10;}
            n = next;
        }
        return n==1;
    }
};
```