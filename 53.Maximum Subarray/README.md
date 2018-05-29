## 题目

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

```
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```


## 解答

* 如果前一个子数组的和大于0，那么当前元素并入前一个子数组从而组成一个更大的子数组可能会有一个新的更大的值
* 如果前一个子数组的和小于0，那么当前元素不并入前一个子数组可以得到更大的和

每次更新得到一个新的和时，与最大值判断，如果大于最大值则更新

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0,max = INT_MIN;
        for(int num : nums){
            if(sum > 0) sum += num;
            else    sum = num;
            if(sum > max)   max = sum;
        }
        return max;
    }
};
```
