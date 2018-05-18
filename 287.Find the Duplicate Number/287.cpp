class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1,r = nums.size() - 1;//l和r初始化成1和n
        while(l < r){
            int mid = (l + r) >> 1;
            int count = 0;//小于等于mid的数的个数
            for(int i = 0;i < nums.size();i++)
                if(nums[i] <= mid)   count++;
            if(count <= mid)
                l = mid + 1;
            else if(count > mid)
                r = mid;
        }
        
        return l;
    }
};