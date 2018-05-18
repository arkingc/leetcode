**题目**：给出包含n+1个元素的数组，所有数字都在1~n范围内，找出数组中冗余的数组

* 不能修改数组
* 要求O(1)的空间复杂度
* 时间复杂度要小于O(n^2)
* 只有1个元素冗余，但是可能冗余很多次

**思路**：假设1~n的中间元素是mid，遍历数组：

* 如果小于等于mid的个数大于mid，说明重复数字出现在1~mid中
* 如果小于等于mid的个数小于等于mid，说明重复数组出现在mid+1~n中

每轮需要遍历n+1个元素，但是每次可以将范围缩小一半，因此时间复杂度小于O(n^2)

```c++
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
```

去掉一个条件，如果可以修改数组，那么遍历数组中的每个数num，如果num不等于当前下标加1。那么将这个数与下标为num - 1的数交换，直到num等于当前下标加1。如果num - 1位置的数和num相等，表示出现重复，因此返回num

```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            int tp;
            while(nums[i] != i + 1){
                if(nums[nums[i] - 1] != nums[i]){
                    tp = nums[nums[i] - 1];
                    nums[nums[i] - 1] = nums[i];
                    nums[i] = tp;
                }
                else
                    return nums[i];
            }
        }
        
        return -1;//输入数据无效
    }
};
```
