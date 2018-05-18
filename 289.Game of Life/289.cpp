class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty())   return;
        
        int rows = board.size(),cols = board[0].size();   
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                int count = board[i][j] & 1 == 1 ? -1 : 0;
                for(int m = max(i - 1,0);m <= min(i + 1,rows - 1);m++)
                    for(int n = max(j - 1,0);n <= min(j + 1,cols - 1);n++)
                        if(board[m][n] & 1 == 1)    count++;
                if(count == 3 || (board[i][j] == 1 && count == 2))
                    board[i][j] |= 2;
            }
        }
        
        for(int i = 0;i < rows;i++)
            for(int j = 0;j < cols;j++)
                board[i][j] >>= 1;
    }
};