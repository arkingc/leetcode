class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows <= 0)    return vector<vector<int>>();
        
        vector<vector<int>> res(1,vector<int>(1,1));
        for(int i = 1;i < numRows;i++){
            vector<int> newline;
            newline.push_back(1);
            for(int j = 1;j < i;j++){
                newline.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            newline.push_back(1);
            res.push_back(newline);
        }
        
        return res;
    }
};