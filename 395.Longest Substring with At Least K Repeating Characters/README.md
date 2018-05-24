## 题目

找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度

示例 1:

```
输入:
s = "aaabb", k = 3

输出:
3

最长子串为 "aaa" ，其中 'a' 重复了 3 次
```

示例 2:

```
输入:
s = "ababbc", k = 2

输出:
5

最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次
```

## 解答

1. 遍历字符串，统计每个字符出现的次数
2. 找到字符串中第一个出现次数少于K的字符，这个字符显然不会出现在满足要求的子串中，因此它将字符串分割成2个子串
3. 递归处理，最长子串必定出现在左边或者右边

```c++
class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> cases(26,0);
        for(char c : s) cases[c - 'a']++;
        
        int len = s.length();
        int idx = 0;
        while(idx < len && cases[s[idx] - 'a'] >= k) {idx++;}
        if(idx == len)  return len;
        
        int left = longestSubstring(s.substr(0,idx),k);
        //这里是个优化：跳过所有相连的、出现次数少于k次的字符
        while(idx < len && cases[s[idx] - 'a'] < k) {idx++;}
        int right = longestSubstring(s.substr(idx),k);
        
        return max(left,right);
    }
};
```

由于题目给出了字符串只包含小写字母，所有map直接使用了vector。如果没有限定字符串的字符范围，可以使用unordered_map<char,int>
