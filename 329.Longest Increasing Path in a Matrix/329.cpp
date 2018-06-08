class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())  return 0;
        
        int rows = matrix.size(),cols = matrix[0].size();
        vector<vector<int>> states(rows,vector<int>(cols,0));
        
        int res = 1;
        for(int i = 0;i < rows;i++)
            for(int j = 0;j < cols;j++){
                int path = longestIncreasingPath(matrix,states,i,j);
                if(path > res)  res = path;
            }
        
        return res;
    }
private:
    int longestIncreasingPath(vector<vector<int>> &matrix,vector<vector<int>> &states,int row,int col){
        if(states[row][col] != 0)   return states[row][col];
        
        int rows = matrix.size(),cols = matrix[0].size();
        int left,right,up,down;
        states[row][col] = 1;
        //left
        if(col > 0 && matrix[row][col - 1] > matrix[row][col]){
            left = longestIncreasingPath(matrix,states,row,col - 1) + 1;
            if(left > states[row][col])  states[row][col] = left; 
        }
        //right
        if(col < cols - 1 && matrix[row][col + 1] > matrix[row][col]){
            right = longestIncreasingPath(matrix,states,row,col + 1) + 1;
            if(right > states[row][col])  states[row][col] = right; 
        }
        //up
        if(row > 0 && matrix[row - 1][col] > matrix[row][col]){
            up = longestIncreasingPath(matrix,states,row - 1,col) + 1;
            if(up > states[row][col])  states[row][col] = up; 
        }
        //down
        if(row < rows - 1 && matrix[row + 1][col] > matrix[row][col]){
            down = longestIncreasingPath(matrix,states,row + 1,col) + 1;
            if(down > states[row][col])  states[row][col] = down; 
        }
        
        return states[row][col];
    }
};