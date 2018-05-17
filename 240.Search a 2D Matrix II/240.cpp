class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())  return false;
        
        int rows = matrix.size() , cols = matrix[0].size();
        int row = 0,col = cols - 1;
        while(row <= rows - 1 && col >= 0){
            if(matrix[row][col] < target)   row++;
            else if(matrix[row][col] > target)  col--;
            else    return true;
        }
        
        return false;
    }
};