class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int sz = nums1.size() + nums2.size();
        int sz1l = 0,sz1r = nums1.size();
        int sz1 = 0,sz2 = 0;
        while(sz1 <= nums1.size()){
            sz1 = (sz1l + sz1r) / 2;
            sz2 = sz / 2 - sz1; 
            int l1 = sz1 == 0 ? INT_MIN : nums1[sz1 - 1];
            int r1 = sz1 == nums1.size() ? INT_MAX : nums1[sz1];
            int l2 = sz2 == 0 ? INT_MIN : nums2[sz2 - 1];
            int r2 = sz2 == nums2.size() ? INT_MAX : nums2[sz2];
            if(l1 > r2)
                sz1r = sz1 - 1;
            else if(l2  > r1)
                sz1l = sz1 + 1;
            else{
                if(sz % 2 == 0){
                    l1 = l1 > l2 ? l1 : l2;
                    r1 = r1 < r2 ? r1 : r2;
                    return (double)(l1 + r1) / 2;
                }
                else{
                    r1 = r1 < r2 ? r1 : r2;
                    return r1;
                }
            }
                
        }
        
        return -1;
    }
};