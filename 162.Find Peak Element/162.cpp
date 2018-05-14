class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ret = -1;
        int l = 0,r = nums.size() - 1,mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(nums[mid] < nums[mid + 1])
                l = mid + 1;
            else if(nums[mid] > nums[mid + 1])
                r = mid;
            //假设输入合法，如果nums[mid] == nums[mid+1]会无限循环
            //为了代码的简洁性暂时不处理这种情况
        }
        return l == r ? l : -1;
    }
};