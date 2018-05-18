class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return nums.size();

        vector<int>::iterator m = nums.begin();  // m will mark the virtual "S.end()".
        for (int& val : nums) {
            //lower_bound使用二分查找，查找[nums.begin(),m)区间内第一个大于等于val的元素
            //返回相应迭代器
            auto it = lower_bound(nums.begin(), m, val);
            *it = val;
            if (it == m)
                m++;
        }

        return m - nums.begin();
    }
};