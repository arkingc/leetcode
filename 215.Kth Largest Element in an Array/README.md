## 基于最小堆

```c++
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
```

## 基于partition

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int idx = -1,target = nums.size() - k,l = 0,r = nums.size() - 1;
        
        while(idx != target){
            idx = partition(nums,l,r);
            if(idx < target) l = idx + 1;
            else if(idx > target) r = idx - 1;
        }
        
        return nums[target];
    }
private:
    int partition(vector<int> &nums,int l,int r){
        int pivot = nums[r];
        int i = l - 1;
        for(int j = l;j < r;j++){
            if(nums[j] < pivot){
                int tp = nums[++i];
                nums[i] = nums[j];
                nums[j] = tp;
            }
        }
        nums[r] = nums[++i];
        nums[i] = pivot;
        return i;
    }
};
```