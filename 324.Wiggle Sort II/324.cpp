class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        //m为偶数下标的个数
        int n = nums.size(), m = (n + 1) >> 1;
        //lambda，将下标i进行映射
        auto mapping=[n](int i)->int{return (1 + 2 * i) % (n | 1);};
        //获取中值
        auto miditr = nums.begin() + m - 1;
        nth_element(nums.begin(), miditr , nums.end());
        int median = *miditr;
    
        //j:          [0,1,2,3,...] （j > k时终止）
        //mapping[j]: [1,3,5,...,0,2,4,...]
        //
        //i:          [0,1,2,3,...]
        //mapping[i]: [1,3,5,...,0,2,4,...]
        //k:          [n-1,n-2,...]
        //mapping[k]: [...,4,2,0,...,5,3,1]
        for (int i = 0, j = 0, k = n - 1; j <= k;) {
            if (nums[mapping(j)] > median) //找到一个比中值大的数
                swap(nums[mapping(i++)], nums[mapping(j++)]);
            else if(nums[mapping(j)] < median)  //找到一个比中值小的数，这里j不变
                swap(nums[mapping(j)], nums[mapping(k--)]);
            else   //找到一个和中值相等的元素
                j++;
        }
    }
};