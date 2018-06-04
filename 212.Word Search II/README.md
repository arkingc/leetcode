## 题目

给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例:

```
输入: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]
```

说明:

你可以假设所有输入都由小写字母 a-z 组成。

提示:

* 你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
* 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？

## 解答

利用字典树Trie来做, 就是将要搜索的单词先添加到字典树中, 然后从地图board的每一个元素搜索, 如果往上下左右搜索的时候其元素可以在字典树中找到, 那么就继续搜索下去, 并且如果搜索到某个结点的时候发现到这个结点构成了一个单词, 那么就将单词添加到结果集合中. 如果在字典树中无法找到这个元素, 那么就结束当前分支的搜索

另外还需要标记搜索过的点, 可以再开一个二维数组来标记, 也可直接在原矩阵上修改, 搜索完之后再改回来

```c++
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || words.empty())   return vector<string>();
        
        TrieNode *root = new TrieNode(),*nd;
         for(auto str: words)  
        {  
            nd = root;  
            for(auto ch: str)  
            {  
                if(!nd->next[ch-'a']) nd->next[ch-'a'] = new TrieNode();  
                nd = nd->next[ch-'a'];  
            }  
            nd->word = true;  
        }  
        
        vector<string> res;
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                dfs(board,root->next[board[i][j]-'a'],i,j,"",res);
            }
        }
        return res;
    }
private:
    struct TrieNode
    {  
        vector<TrieNode*> next;  
        bool word;  
        TrieNode(): next(vector<TrieNode*>(26, NULL)), word(false){}  
    };
    
    void dfs(vector<vector<char>>& board,TrieNode *nd,int x,int y,string word,vector<string> &res){
        if(!nd || board[x][y] == '#')
            return;
        
        char c = board[x][y];
        word += c;
        if(nd->word){
            res.push_back(word);
            nd->word = false;    //防止重复
        }
        
        board[x][y] = '#';
        if(x - 1 >= 0)  
            dfs(board,nd->next[board[x - 1][y] - 'a'],x - 1,y,word,res);
        if(x + 1 < board.size())  
            dfs(board,nd->next[board[x + 1][y] - 'a'],x + 1,y,word,res);
        if(y - 1 >= 0)
            dfs(board,nd->next[board[x][y - 1] - 'a'],x,y - 1,word,res);
        if(y + 1 < board[0].size())
            dfs(board,nd->next[board[x][y + 1] - 'a'],x,y + 1,word,res);
        board[x][y] = c;
    }
};
```
