class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> min(nums.begin(),nums.begin() + k);
        make_heap(min.begin(),min.end(),greater<int>());
        
        for(int i = k;i < nums.size();i++){
            if(nums[i] > min.front()){
                pop_heap(min.begin(),min.end(),greater<int>());
                min.pop_back();
                min.push_back(nums[i]);
                push_heap(min.begin(),min.end(),greater<int>());
            }
        }
        
        return min.front();
    }
};