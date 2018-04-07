class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        permute(nums,0,res);
        
        return res;
    }
private:
    void permute(vector<int> &nums,int idx,vector<vector<int>> &res){
        if(idx == nums.size())
            res.push_back(nums);
        
        for(int i = idx;i < nums.size();i++){
            int tp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tp;
            
            permute(nums,idx + 1,res);
            
            tp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tp;
        }
    }    
};