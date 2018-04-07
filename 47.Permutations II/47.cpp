class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        
        permuteUnique(nums,0,res);
        
        return res;
    }
    
private:
    void permuteUnique(vector<int>& nums,int idx,vector<vector<int>> &res){
        if(idx == nums.size()){
            res.push_back(nums);
        }
        
        set<int> s;
        for(int i = idx;i < nums.size();i++){
            if(s.find(nums[i]) != s.end()) continue;
            
            s.insert(nums[i]);
            
            int tp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tp;
            
            permuteUnique(nums,idx + 1,res);
            
            tp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tp;
        }
    }
};