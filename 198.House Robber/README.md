## 题目

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

```
输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
```

示例 2:

```
输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
```

## 解答

动态规划，如果state[i]表示从i和i之后的房屋内能偷窃到的最高金额，那么第i间房屋可以选择偷窃或者不偷窃：

* 如果偷窃，state[i] = nums[i] + state[i + 2]
* 如果不偷窃，state[i] = state[i + 1];

因此，state[i] = max(nums[i] + state[i + 2],state[i + 1])

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())    return 0;
        if(nums.size() == 1)  return nums[0];
        
        vector<int> state(nums.size() + 1,0);
        state[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = nums.size() - 2;i >= 0;i--)
            state[i] = max(state[i + 1],nums[i] + state[i + 2]);
        
        return state[0];
    }
};
```
