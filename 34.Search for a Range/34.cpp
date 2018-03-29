class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = searchRangel(nums,target);
        int r = searchRanger(nums,target);
        
        vector<int> v;
        v.push_back(l);
        v.push_back(r);
        return v;
    }
    
    int searchRangel(const vector<int> &nums,int target)
    {
        int l = 0,r = nums.size() - 1;
        int mid;
        
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] == target){
                if(mid == 0 || nums[mid - 1] != nums[mid])  return mid;
                else   r = mid - 1;
            }
            else if(nums[mid] > target) r = mid - 1;
            else    l = mid + 1;
        }
        
        return -1;
    }
    
    int searchRanger(const vector<int> &nums,int target)
    {
        int l = 0,r = nums.size() - 1;
        int mid,end = r;
        
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] == target){
                if(mid == end || nums[mid + 1] != nums[mid])  return mid;
                else   l = mid + 1;
            }
            else if(nums[mid] > target) r = mid - 1;
            else    l = mid + 1;
        }
        
        return -1;
    }
};