class Solution {
public:
    int numSquares(int n) {
        vector<int> state(n + 1,INT_MAX);
        state[0] = 0;
        
        for(int i = 1;i <= n;i++){
            int q = sqrt(i);
            if(q * q == i)  state[i] = 1;
            else{
                for(int j = 1;j <= q;j++){
                    if(state[i - j * j] + 1 < state[i])
                        state[i] = state[i - j * j] + 1;
                }
            }
        }
        
        return state[n];
    }
};