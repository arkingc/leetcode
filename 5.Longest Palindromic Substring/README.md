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

### 方法一：动态规划

使用一个矩阵记录每个子串是不是回文，对于一个是回文的子串，判断该子串是不是更长的子串，如果是则更新结果：

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

### 方法二：从中心扩展

以字符串的每个字符为中心，向两边扩展，找出以每个字符为中心的回文，其中最长的就是结果

注意：字符串的中心可能是多个相同的字符，所以每次处理以连续的相同字符为中心

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        
        string res = "";
        int j;
        for(int i = 0;i < s.length();i = j){
            //向右找到第一个不相同的字符，i~(j-1)为相同字符
            for(j = i + 1;j < s.length() && s[j] == s[i];j++) {}
            int len = longestPalindrome(s,i,j - 1);
            if(len > res.length())
                res = s.substr(i - (len - (j - i)) / 2,len);
        }
        return res;
    }
private:
    int longestPalindrome(const string &s,int i,int j){
        int l = i - 1,r = j + 1,len = s.length();
        int count = j - i + 1;
        while(l >= 0 && r < len && s[l--] == s[r++])
                count += 2;
        return count;
    }
};
```