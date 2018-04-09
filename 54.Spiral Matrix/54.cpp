class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())  return vector<int>();
        
        vector<int> res;
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        for(int i = 0;i <= (rows - 1) / 2 && i <= (columns - 1) / 2;i++){
            int left = i,right = columns - 1 - left,up = i,down = rows - 1 - up;
            for(int j = left;j <= right;j++)
                res.push_back(matrix[up][j]);
            for(int j = up + 1;j <= down;j++)
                res.push_back(matrix[j][right]);
            if(up < down)
                for(int j = right - 1;j >= left;j--)
                    res.push_back(matrix[down][j]);
            if(right > left)
                for(int j = down - 1;j > up;j--){
                    res.push_back(matrix[j][left]);
            }
        }
        
        return res;
    }
};