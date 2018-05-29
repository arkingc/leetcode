## 题目

给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

```
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
```

两个字符串完全匹配才算匹配成功。

说明:

* s 可能为空，且只包含从 a-z 的小写字母。
* p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。

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
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
```

示例 3:

```
输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
```

示例 4:

```
输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
```

示例 5:

```
输入:
s = "acdcb"
p = "a*c?b"
输入: false
```

## 解答

使用动态规划

给出字符串s，和字符串模板p。假设matches\[0\]\[0\]表示s和p是否能匹配。可以根据p[0]进行分析：

* 如果p[0]==‘\*’，那么可以选择\*匹配一个字符，或者不匹配。如果匹配一个字符，那么matches\[0\]\[0\]取决于s.substr[1]与p是否匹配；如果\*不匹配一个字符，那么matches\[0\]\[0\]取决于s与p.substr[1]是否匹配。即matches\[0\]\[0\] = matches\[1\]\[0\] || matches\[0\]\[1\]
* 如果p[0]=='?'，那么必须匹配一个字符，因此matches\[0\]\[0\] = matches\[1\]\[1\]
* 否则，matches\[0\]\[0\] = s\[0\] == p\[0\] && matches\[1\]\[1\]

因此可以根据上面3种情况得到状态转移方程

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length(),len2 = p.length();
        
        vector<vector<char>> matches(len1 + 1,vector<char>(len2 + 1));
        for(int i = 0;i < len1;i++)  // p == ""
            matches[i][len2] = 0;
        matches[len1][len2] = 1;       // p == "" && s == ""
        for(int j = len2 - 1;j >= 0;j--) // s == ""
            matches[len1][j] = (p[j] == '*' && matches[len1][j + 1]);
        
        for(int i = len1 - 1;i >= 0;i--){ // s.substr[i] match p.substr[j] ?
            for(int j = len2 - 1;j >= 0;j--){
                if(p[j] == '?')
                    matches[i][j] = matches[i + 1][j + 1];
                else if(p[j] == '*')
                    matches[i][j] = matches[i + 1][j] || matches[i][j + 1];
                else
                    matches[i][j] = (s[i] == p[j] && matches[i + 1][j + 1]);
            }
        }
        
        return matches[0][0];
    }
};
```