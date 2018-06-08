## 题目

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

```
s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
```

注意事项：您可以假定该字符串只包含小写字母。

## 解答

题目可以假定字符串只包含小写字母，因此使用26个元素的数组，分别表示字母'a'-'z'出现的位置，因为出现的位置大于等于0，因此，用-1表示字母并未在字符串中出现，-2表示出现多次，那么最后遍历这个数组，不等于-1和-2的最小值就是第一个唯一字符出现的位置

```c++
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> idxArray(26,-1);
        for(int i = 0;i < s.length();i++){
            if(idxArray[s[i] - 'a'] == -1)   idxArray[s[i] - 'a'] = i;
            else idxArray[s[i] - 'a'] = -2;
        }
        
        int minIdx = -1;      
        for(int idx : idxArray)
            if(idx != -1 && idx != -2){
                if(minIdx == -1)    minIdx = idx;
                else if(idx < minIdx) minIdx = idx;
            }
        
        return minIdx;
    }
};
```