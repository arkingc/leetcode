class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() != 9 && board[0].size() != 9)   return false;
        
        int nums[10],i,j,m;
        //1.检测每行是否满足要求
        for(i = 0;i < 9;i++){
            for(m = 0;m < 10;m++)   nums[m] = 0;
            for(j = 0;j < 9;j++){
                if(board[i][j] == '.')  continue;
                else if(board[i][j] >= '0' && board[i][j] <= '9'){
                    if(nums[board[i][j] - '0'] == 0)    nums[board[i][j] - '0'] = 1;
                    else    return false;
                }
                else    return false;
            }
        }
        
        //2.检测每列是否满足要求
        for(j = 0;j < 9;j++){
            for(m = 0;m < 10;m++)    nums[m] = 0;
            for(i = 0;i < 9;i++){
                if(board[i][j] == '.')  continue;
                if(nums[board[i][j] - '0'] == 0)    nums[board[i][j] - '0'] = 1;
                else return false;
            }
        }
        
        //3.检测9个子格是否满足要求
        int x,y;
        for(i = 0;i < 9;i += 3){
            for(j = 0;j < 9;j += 3){
                //检查每个3*3子格
                for(m = 0;m < 10;m++)    nums[m] = 0;
                for(x = i;x < i + 3;x++){
                    for(y = j;y < j + 3;y++){
                        if(board[x][y] == '.')  continue;
                        if(nums[board[x][y] - '0'] == 0)    nums[board[x][y] - '0'] = 1;
                        else return false;
                    }
                }
            }
        }
        
        return true;
    }
};