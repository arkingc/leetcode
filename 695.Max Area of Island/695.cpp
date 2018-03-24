/*
 * DFS
 */

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        int res = 0;
        int rows = grid.size(),columns = grid[0].size();   
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < columns;j++){
                int area = DFS(grid,i,j,rows,columns);
                res = area > res ? area : res; 
            }
        }
        
        return res;
    }
    
    int DFS(vector<vector<int>> &grid,int row,int column,int rows,int columns){
        //越界或者不连通
        if(row < 0 || row >= rows || column < 0 || column >= columns || grid[row][column] == 0)
            return 0;
        
        int count = 1;
        grid[row][column] = 0;//防止重复计算
        /*遍历该顶点的四个方向*/
        count += DFS(grid,row - 1,column,rows,columns);
        count += DFS(grid,row + 1,column,rows,columns);
        count += DFS(grid,row,column - 1,rows,columns);
        count += DFS(grid,row,column + 1,rows,columns);
        
        return count;
    }
};