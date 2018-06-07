class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> countMap;
        
        vector<int> res;
        for(int num : nums1)  countMap[num]++;
        
        for(int num : nums2)
            if(countMap[num]-- > 0)
                res.push_back(num);
        
        return res;
    }
};