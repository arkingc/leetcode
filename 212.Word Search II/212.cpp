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