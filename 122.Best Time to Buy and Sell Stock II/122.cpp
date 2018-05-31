class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX,maxprofit = 0;
        for(int i = 0;i < prices.size();i++){
            if(prices[i] < buy) buy = prices[i];
            else if(prices[i] > buy){
                maxprofit += prices[i] - buy;
                buy = prices[i];
            }
        }
        return maxprofit;
    }
};