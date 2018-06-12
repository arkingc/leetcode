## 题目

给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

```
'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串 (s) ，而不是部分字符串。
```

说明:

* s 可能为空，且只包含从 a-z 的小写字母。
* p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

示例 1:

```
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
```

示例 2:

```
输入:
s = "aa"
p = "a*"
输出: true
解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
```

示例 3:

```
输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
```

示例 4:

```
输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
```

示例 5:

```
输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
```

## 解答

**动态规划**

创建一个二维矩阵记录状态。`state[i][j]`表示`s[0~i-1]`能否和`p[0~j-1]`匹配：

* 如果`p[j - 1] == '*'`，此时`p[j - 2]`可以使用也可以不使用
    - 如果使用，`state[i][j] = ((p[j - 2] == '.' || p[j - 2] == s[i - 1]) && state[i - 1][j])`
    - 如果不使用，`state[i][j] = state[i][j - 2]`
* 如果`p[j - 1] == '.'`，此时`state[i][j] = state[i - 1][j - 1]`
* 否则，`state[i][j] = p[j - 1] == s[i - 1] && state[i - 1][j - 1]`

**注意二维bool矩阵的创建方法，这里不要使用vector**

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length(),len2 = p.length();
        
        bool **state = new bool*[len1 + 1];
        for(int i = 0;i <= len1;i++)
            state[i] = new bool[len2 + 1];
        
        //第一列，p = ""
        state[0][0] = true;
        for(int i = 1;i <= len1;i++)    state[i][0] = false;
        
        //第一行，s = ""
        state[0][1] = false;
        for(int j = 2;j <= len2;j++)    state[0][j] = (p[j - 1] == '*') ? (state[0][j - 2]) : false;
        
        for(int i = 1;i <= len1;i++)
            for(int j = 1;j <= len2;j++){
                if(p[j - 1] == '*')
                    state[i][j] = state[i][j - 2] || ((p[j - 2] == '.' || p[j - 2] == s[i - 1]) && state[i - 1][j]);
                else if(p[j - 1] == '.')
                    state[i][j] = state[i - 1][j - 1];
                else
                    state[i][j] = (p[j - 1] == s[i - 1]) && state[i - 1][j - 1];
            }
        
        return state[len1][len2];
    }
};
```