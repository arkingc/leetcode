class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int row = 0;row < grid.size();row++){
            for(int col = 0;col < grid[0].size();col++){
                if(grid[row][col] == '1'){
                    count++;
                    dfs(grid,row,col);
                }
            }
        }
        /* 如果不想改动grid，可以将所有的'#'变回'1' 
        for(int row = 0;row < grid.size();row++){
            for(int col = 0;col < grid[0].size();col++){
                if(grid[row][col] == '#'){
                    grid[row][col] = '1';
                }
            }
        }
        */
        return count;
    }
    
private:
    void dfs(vector<vector<char>>& grid,int row,int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != '1')   return;
        //没越界，并且为'1'
        grid[row][col] = '#';
        dfs(grid,row - 1,col);
        dfs(grid,row + 1,col);
        dfs(grid,row,col - 1);
        dfs(grid,row,col + 1);
    }
};