class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0)    count++;
            else if(count != 0) nums[i - count] = nums[i];
        }
        
        int end = nums.size() - 1;
        while(count--)
            nums[end--] = 0;
    }
};