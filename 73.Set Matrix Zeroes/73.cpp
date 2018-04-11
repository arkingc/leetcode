class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0 = false;
        int rows = matrix.size();
        int columns = rows > 0 ? matrix[0].size() : 0;
        
        for(int i = 0;i < rows;i++){
            if(matrix[i][0] == 0) col0 = true;
            for(int j = 1;j < columns;j++){
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        
        for(int j = 1;j < columns;j++)
            if(matrix[0][j] == 0)
                for(int i = 1;i < rows;i++)
                    matrix[i][j] = 0;
        
        for(int i = 0;i < rows;i++)
            if(matrix[i][0] == 0)
                for(int j = 1;j < columns;j++)
                    matrix[i][j] = 0;
        
        if(col0)
            for(int i = 0;i < rows;i++)
                matrix[i][0] = 0;
        
    }
};