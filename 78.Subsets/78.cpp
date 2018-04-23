class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> res;
        subsets(nums,0,res,subset);
        return res;
    }
    
private:
    void subsets(const vector<int> &nums,int idx,vector<vector<int>> &res,vector<int> subset){
        if(idx < 0) return;
        else if(idx == nums.size()){
            res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[idx]);
        subsets(nums,idx + 1,res,subset);
        subset.pop_back();
        subsets(nums,idx + 1,res,subset);
    }
};