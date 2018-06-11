## 题目

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

```
输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。
```

示例 2：

```
输入: "cbbd"
输出: "bb"
```

## 解答

**动态规划**，使用一个矩阵记录每个子串是不是回文，对于一个是回文的子串，判断该子串是不是更长的子串，如果是则更新结果：

<div align="center"> <img src="../img/5.png"/> </div>

下面的解法对状态进行了压缩，使用的是一维矩阵而不是二维矩阵，但是思想相同：

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        
        int len = s.length();
        string res = "";
        //做了状态压缩
        bool *state = new bool[len];
        state[len - 1] = true;
        for(int i = len - 2;i >= 0;i--){
            for(int j = len - 1;j >= i;j--){
                if(i == j)
                    state[j] = true;
                else if(s[i] == s[j]){
                    if(i == j - 1)   state[j] = true;
                    else    state[j] = state[j - 1];
                }
                else 
                    state[j] = false;
                if(state[j] && (j - i + 1) > res.length())
                    res = s.substr(i,(j - i + 1));
            }
        }
        return res;
    }
};
```