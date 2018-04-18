class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redcount = 0, whitecount = 0;
        
        for(int i = 0;i < nums.size();i++){
            if (nums[i] == 0)
                redcount++;
            else if(nums[i] == 1)
                whitecount++;
            else if(nums[i] == 2)
                continue;
            else
                return;
        }
        
        for(int i = 0;i<nums.size();i++){
            if(redcount){
                nums[i] = 0;
                redcount--;
            }
            else if(whitecount){
                nums[i] = 1;
                whitecount--;
            }
            else
                nums[i] = 2;
        }
    }
};