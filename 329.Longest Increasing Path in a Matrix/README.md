## 题目

给定一个整数矩阵，找出最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

```
输入: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
输出: 4 
解释: 最长递增路径为 [1, 2, 6, 9]。
```

示例 2:

```
输入: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
输出: 4 
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
```

## 解答

假设`state[i][j]`表示以`第i行，第j列`元素为起点的最长序列的长度。那么最终我们就是要求所有`state[i][j]`中的最大值。如果知道其中某个`state[i][j]`怎么求，那么问题也就解决了

既然`state[i][j]`表示以`第i行，第j列`元素为起点的最长序列的长度，那么`state[i][j]`肯定是以元素`matrix[i][j]`为起点的4个方向(`上下左右`)上最长的序列长度。以向上的序列为例：

* 如果`matrix[i - 1][j] >= matrix[i][j]`：那么只包含当前元素，最长序列长度为1
* 如果`matrix[i - 1][j] < matrix[i][j]`：那么最长序列的长度就是`state[i - 1][j] + 1`

因此，可以求出4个方向上的递增序列的长度，那么`state[i][j]`就是4个序列中最长序列的长度

* 为了防止求重复的子问题，使用`state`数组保存中间值
* 注意，不会产生无限循环，比如：如果求`matrix[i][j]`，需要依赖`matrix[i-1][j]`。那么求`matrix[i - 1][j]`肯定不需要依赖`matrix[i][j]`，因为只有满足递增性质时，才会发生递归

```c++
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
```