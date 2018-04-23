class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())   return word.empty();
        if(word.empty())    return true;
        
        
        vector<vector<char>> flags;
        for(int i = 0;i < board.size();i++){
            vector<char> tp;
            for(int j = 0;j < board[0].size();j++)
                tp.push_back(0);
            flags.push_back(tp);
        }
        
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++)
                if(exist(board,flags,word,i,j,0))
                    return true;
        }
        
        return false;
    }
    
private:
    bool exist(vector<vector<char>>& board, vector<vector<char>> &flags,string word,int row,int col,int idx){
        if(idx == word.size())  return true;
        
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || 
           flags[row][col] == 1 || board[row][col] != word[idx])
            return false;
        
        flags[row][col] = 1;
        bool ret = exist(board,flags,word,row + 1,col,idx + 1) || exist(board,flags,word,row - 1,col,idx + 1)
                    || exist(board,flags,word,row,col + 1,idx + 1) || exist(board,flags,word,row,col - 1,idx + 1);
        flags[row][col] = 0;
        return ret;
    }
};