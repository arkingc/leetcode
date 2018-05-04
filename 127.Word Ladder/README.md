## BFS

<div align="center"> <img src="../img/127-1.png"/> </div>

```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size() != endWord.size())  return 0;
        
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord) == dict.end())    return 0;
        
        deque<string> q;    //for BFS
        q.push_back(beginWord);
        
        int length = beginWord.size();
        int step = 0;
        
        while(!q.empty()){
            ++step;
            for(int level = q.size();level > 0;level--){//一层一层处理
                string s = q.front();
                q.pop_front();
                for(int i = 0;i < length;i++){
                    char c = s[i];
                    for(int j = 'a';j <= 'z';j++){
                        s[i] = j;
                        if(s == endWord)    return step + 1;
                        else if(dict.find(s) == dict.end()) continue;
                        q.push_back(s);
                        dict.erase(s);
                    }
                    s[i] = c;
                }
            }
        }
        
        return 0;
    }
};
```

## 双向BFS

<div align="center"> <img src="../img/127-2.png"/> </div>

```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size() != endWord.size())  return 0;
        
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord) == dict.end())    return 0;
        
        //双向BFS，所以需要两个队列，但是每次需要查找一个字符串是否在另一个队列中，
        //所以使用unordered_set替代deque
        unordered_set<string> bq = {beginWord};
        unordered_set<string> eq = {endWord};
        dict.erase(beginWord);
        dict.erase(endWord);
        
        int length = beginWord.size();
        int step = 0;
        
        while(!bq.empty() && !eq.empty()){
            if(bq.size() > eq.size())//每次从首端和尾端选择节点较少的一层处理
                std::swap(bq,eq);
        
            step++;
            unordered_set<string> q;
            
            for(auto s : bq){//一层一层处理
                for(int i = 0;i < length;i++){
                    char c = s[i];
                    for(int j = 'a';j <= 'z';j++){
                        s[i] = j;
                        if(eq.find(s) != eq.end())  return step + 1;
                        else if(dict.find(s) == dict.end()) continue;
                        q.insert(s);
                        dict.erase(s);
                    }
                    s[i] = c;
                }
            }
            
            std::swap(q,bq);
        }
        
        return 0;
    }
};
```

<div align="center"> <img src="../img/127-3.png"/> </div>

[参考](http://zxi.mytechroad.com/blog/searching/127-word-ladder/)