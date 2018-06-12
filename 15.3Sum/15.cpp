class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return vector<vector<int>>();
        
        sort(nums.begin(),nums.end());
    
        vector<vector<int>> res;
        
        for(int i = 0;i < nums.size() - 2;i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                int target = 0 - nums[i];
                int l = i + 1,r = nums.size() - 1;
                while(l < r){
                    int sum = nums[l] + nums[r];
                    if(sum < target){
                        while(l < r && nums[l + 1] == nums[l])    l++;
                        l++;
                    }
                    else if(sum > target){
                        while(l < r && nums[r - 1] == nums[r])    r--;
                        r--;
                    }  
                    else{
                        vector<int> triplet = {nums[i],nums[l],nums[r]};
                        res.push_back(triplet);
                        while(l < r && nums[l + 1] == nums[l])    l++;
                        while(l < r && nums[r - 1] == nums[r])    r--;
                        l++;r--;
                    }
                }
            }
        }
        
        return res;
    }
};