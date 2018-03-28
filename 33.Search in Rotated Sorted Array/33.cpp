class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        
        int begin = 0 , end = nums.size() - 1;
        int mid;
        while(begin <= end){
            mid = (begin + end) / 2;
            if(nums[mid] > nums[end]){//mid在左边
                if(nums[mid] == target)  return mid;
                else if(nums[mid] < target || target <= nums[end])    begin = mid + 1;
                else    end = mid - 1;
            }
            else{//mid在右边
                if(nums[mid] == target) return mid;
                else if(nums[mid] < target && target <= nums[end])  begin = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};