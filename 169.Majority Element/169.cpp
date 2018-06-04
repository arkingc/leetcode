class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty())    return 0;
        
        int count = 1,res = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(count == 0){
                res = nums[i];
                count = 1;
            }
            else{
                if(nums[i] == res)  count++;
                else    count--;
            }
        }
        return res;
    }
};