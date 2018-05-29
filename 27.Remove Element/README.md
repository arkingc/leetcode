## 题目

给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1:

```
给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。
```

示例 2:

```
给定 nums = [0,1,2,2,3,0,4,2], val = 2,

函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。

你不需要考虑数组中超出新长度后面的元素
```

## 解答

如果值为val的元素有m个，那么相当于所有在val后面的元素都要前移，最终后面留下m个位置

遍历数组，每出现一次val时，计数count增加一，如果元素的值不为val，那么前移count步

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == val)  count++;
            else if(count != 0)    nums[i - count] = nums[i];
        }
        
        return nums.size() - count;
    }
};
```