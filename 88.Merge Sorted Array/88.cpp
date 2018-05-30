class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.empty() || nums2.empty() || m < 0 || n < 0)  return ;
        
        int end1 = m - 1,end2 = n - 1,end = nums1.size() - 1;
        while(end1 >= 0 && end2 >= 0){
            if(nums1[end1] >= nums2[end2])
                nums1[end--] = nums1[end1--];
            else
                nums1[end--] = nums2[end2--];
        }
        
        while(end2 >= 0)
            nums1[end--] = nums2[end2--];
    }
};