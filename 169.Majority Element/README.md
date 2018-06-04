## 题目

给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

```
输入: [3,2,3]
输出: 3
```

示例 2:

```
输入: [2,2,1,1,1,2,2]
输出: 2
```

## 解答

该数字出现的次数超过其它数字出现的次数之和（因此，考虑使用2个变量，一个保存数字，一个保存次数。当遍历到下一个数字时，如果下一数字和之前保存的数字相同，则次数加1，如果下一数字和之前保存的数字不同，则次数减1。如果次数为0，则需保存下一个数字，并把次数设为1,最后一次把次数设为1时对应的数字就是结果）​

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty())    return 0;
        
        int count = 1,res = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(count == 0){
                res = nums[i];
                count = 1;
            }
            else{
                if(nums[i] == res)  count++;
                else    count--;
            }
        }
        return res;
    }
};
```