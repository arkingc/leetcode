class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())    return true;
        
        int rest = 0;//步长为非负数，这里初始化为0
        
        int i;
        for(i = 0;i < nums.size();i++){
            if(rest == 0 || nums[i] > --rest)   rest = nums[i];
            if(rest == 0 && i < nums.size() - 1)   return false;
        }
    
        return true;
    }
};