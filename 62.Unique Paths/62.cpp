class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0)    return 0;
        if(m == 1 || n == 1)    return 1;
        
        vector<int> state;
        
        for(int j = 0;j < n;j++)    state.push_back(1);
        
        for(int i = m - 2;i >= 0;i--){
            for(int j = n - 2;j >= 0;j--){
                //状态转移方程
                state[j] = state[j+1] + state[j];
            }
        }
        
        return state[0];
    }
};