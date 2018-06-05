## 题目

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。

示例 1:

```
输入: s = "anagram", t = "nagaram"
输出: true
```

示例 2:

```
输入: s = "rat", t = "car"
输出: false
```

说明:

你可以假设字符串只包含小写字母。

进阶:

如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

## 解答

### 方法一

将两个字符串按字典序排序，然后判断是否相等

### 方法二

使用哈希表，统计字符串s中各字符的出现次数，然后遍历字符串t，如果遇到一个s中的字符，则计数减1，如果字符不在s中，则返回false。最终如果哈希表中所有字符的计数都刚好减为0那么就是异位词：

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        for(char c : s)
            map[c]++;
        
        for(char c : t){
            if(map[c] == 0) return false;
            else    map[c]--;
        }
        
        for(auto p : map)
            if(p.second > 0)
                return false;
        
        return true;
    }
};
```