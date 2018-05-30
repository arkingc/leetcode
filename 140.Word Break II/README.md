## 题目

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

* 分隔时可以重复使用字典中的单词。
* 你可以假设字典中没有重复的单词。

示例 1：

```
输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]
```

示例 2：

```
输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。
```

示例 3：

```
输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]
```

## 解答

[参考](https://www.youtube.com/watch?v=JqOIRBC0_9c)

```c++
// Author: Huahua
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        return wordBreak(s, dict);
    }
private:
    // >> append({"cats and", "cat sand"}, "dog");
    // {"cats and dog", "cat sand dog"}
    vector<string> append(const vector<string>& prefixes, const string& word) {
        vector<string> results;
        for(const auto& prefix : prefixes)
            results.push_back(prefix + " " + word);
        return results;
    }
    
    const vector<string>& wordBreak(string s, unordered_set<string>& dict) {
        // Already in memory, return directly
        if(mem_.count(s)) return mem_[s];
        
        // Answer for s
        vector<string> ans;
        
        // s in dict, add it to the answer array
        if(dict.count(s)) 
            ans.push_back(s);
        
        for(int j=1;j<s.length();++j) {
            // Check whether right part is a word
            const string& right = s.substr(j);
            if (!dict.count(right)) continue;
            
            // Get the ans for left part
            const string& left = s.substr(0, j);
            const vector<string> left_ans = 
                append(wordBreak(left, dict), right);
            
            // Notice, can not use mem_ here,
            // since we haven't got the ans for s yet.
            ans.insert(ans.end(), left_ans.begin(), left_ans.end());
        }
        
        // memorize and return
        mem_[s].swap(ans);
        return mem_[s];
    }
private:
    unordered_map<string, vector<string>> mem_;
};
```

我自己的感觉也是n(n^2)的时间复杂度（不算字符串处理的时间），但是超时，暂时没明白原因：

```c++
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(s.length() == 0)   return vector<string>();
        
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        
        int len = s.length();
        unordered_map<string,vector<string>> states;
        if(dict.find(s.substr(len - 1)) != dict.end()) 
            states[s.substr(len - 1)].push_back(s.substr(len - 1));
        for(int l = len - 2;l >= 0;l--){
            string substr = s.substr(l);
            for(int r = l;r < len;r++){
                string word = s.substr(l,r - l + 1);
                if(dict.find(word) != dict.end()){
                    string str = s.substr(r + 1); //剩余字符串
                    if(str == "")
                        states[substr].push_back(word);
                    else if(states.find(str) != states.end()){
                        vector<string> results;
                        for(const string &s : states[str])
                            results.push_back(word + " " + s);
                        states[substr].insert(states[substr].end(),results.begin(),results.end());
                    }
                }
            }
        }
        
        return states[s];
    }
};
```