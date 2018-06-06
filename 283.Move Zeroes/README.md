## 题目

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

```
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
```

说明:

1. 必须在原数组上操作，不能拷贝额外的数组。
2. 尽量减少操作次数。

## 解答

对0计数，遍历到非0数时，根据0的计数决定向前移动多少。最后根据0的计数将数组尾端的相应个数的元素赋值为0

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0)    count++;
            else if(count != 0) nums[i - count] = nums[i];
        }
        
        int end = nums.size() - 1;
        while(count--)
            nums[end--] = 0;
    }
};
```