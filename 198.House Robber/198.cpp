class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())    return 0;
        if(nums.size() == 1)  return nums[0];
        
        vector<int> state(nums.size() + 1,0);
        state[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = nums.size() - 2;i >= 0;i--)
            state[i] = max(state[i + 1],nums[i] + state[i + 2]);
        
        return state[0];
    }
};