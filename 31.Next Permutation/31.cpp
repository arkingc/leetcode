class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0)
            return;
        
        int i;
        for(i = sz - 2;i >= 0;i--){
            if(nums[i] < nums[i + 1]){
                int idx = i + 1;//右边降序序列中，需要与nums[i]交换的元素的下标
                for(int j = idx;j < sz;j++){
                    if(nums[j] > nums[i]) idx = j;
                    else    break;
                }
                
                int tp = nums[i];
                nums[i] = nums[idx];
                nums[idx] = tp;
                
                break;
            }
        }
        
        i++;
        int j = sz - 1;
        while(i < j){
            nums[i] = nums[i] + nums[j];
            nums[j] = nums[i] - nums[j];
            nums[i] = nums[i] - nums[j];
            i++;
            j--;
        }
    }
};