class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty() || amount == -1)  return -1;
        
        vector<int> state(amount + 1,-1);
        state[0] = 0;
        
        for(int price = 1;price <= amount;price++){
            for(int i = 0;i < coins.size();i++)
                if(coins[i] <= price && state[price - coins[i]] != -1)
                    if(state[price] == -1 || state[price] > state[price - coins[i]] + 1)
                        state[price] = state[price - coins[i]] + 1;
        }
        
        return state[amount];
     }
};