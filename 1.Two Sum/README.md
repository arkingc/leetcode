## 题目

给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

```
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

## 解答

将元素值和小标记录在哈希表中，对于一个数num，可以快速查询哈希表中是否存在target-num，存在则找到答案

边遍历边查询，边向哈希表中添加元素，这样方便处理含相同元素的情况

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> res;
        for(int i = 0;i < nums.size();i++){
            if(map.find(target - nums[i]) != map.end()){
                res.push_back(map[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            map[nums[i]] = i;
        }
        return res;
    }
};
```