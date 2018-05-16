class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() <= 1)    return vector<int>();
        
        vector<int> res(nums.size(),0); 
        res[0] = 1;
        for(int i = 1;i < nums.size();i++){
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        int product = 1;
        for(int i = nums.size() - 2;i >=0;i--){
            product *= nums[i + 1];
            res[i] *= product;
        }
        
        return res;
    }
};