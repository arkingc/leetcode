## 题目

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

```
输入: "A man, a plan, a canal: Panama"
输出: true
```

示例 2:

```
输入: "race a car"
输出: false
```

## 解答

注意题目要求，**只考虑字母和数字，同时可以忽略大小写**，意味着其它无效字符会被忽略

使用两个变量l和r，一个从字符串左边出发，一个从右边出发，每次都找到一个数字或字母。因为忽略大小写，因此可以统一使用toupper转换为大写进行比较，相等则继续，直到l>=r，说明是一个有效回文。否则不是有效回文

```c++
class Solution {
public:
    bool isPalindrome(string s) {
        for(int l = 0,r = s.length() - 1;l < r;l++,r--) {
            while(!isalnum(s[l]) && l < r) {l++;}
            while(!isalnum(s[r]) && r > l) {r--;}
            if(toupper(s[l]) != toupper(s[r]))  return false;
        }
        return true;
    }
};
```