给定一个整数数组 `nums` ，找出乘积最大的连续子数组（该数组至少包含一个数）

示例 1:

```
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
```

示例 2:

```
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是连续子数组。
```

### 解答

假设`max_local[i]`表示以`nums[i]`结尾的连续子数组的最大积，如果能求出所有`max_local`，那么最大者就是答案

现在看怎么求`max_local[i]`：

* 如果`max_local[i - 1]`为`0`
    - 当`nums[i]`大于等于`0`时，`max_local[i] = nums[i]`，与前面的子数组无关
    - 当`nums[i]`小于`0`时，`max_local[i] = 0`
* 否则，如果`nums[i]`与`max_local[i - 1]`符号相同，那么`max_local[i] = nums[i] * max_local[i - 1]`，此时将前面的连续子数组并入
* 否则，如果`nums[i]`与`max_local[i - 1]`符号不同，那么`nums[i] * max_local[i - 1]`是以`nums[i]`结尾的连续子数组的最小积，设为`min_local[i]`，如果知道`min_local[i - 1]`，那么就能求出`max_local[i]`：`max_local[i] = min_local[i - 1] * nums[i]`

因此，要求出max_local[i]，同时需要维护连续子数组的最小积——`min_local`数组，对上面的分析进行总结：因为`nums[i]`可能与`max_local[i - 1]`同号，可能异号，`max_local[i - 1]`也可能为`0`。所以`max_local[i]`取决于3个值：`max_local[i - 1]*nums[i]`、`min_local[i - 1]*nums[i]`、`nums[i]`（隐含了状态转移方程）

```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())    return 0;
        
        int max_global = nums[0];
        int max_local = nums[0],min_local = nums[0];
        
        for(int i = 1;i < nums.size();i++){
            int _max = max(max_local * nums[i],min_local * nums[i],nums[i]);
            int _min = min(max_local * nums[i],min_local * nums[i],nums[i]);
            max_local = _max;
            min_local = _min;
            if(max_local > max_global)  max_global = max_local;
        }
        
        return max_global;
    }
private:
    int max(int num1,int num2,int num3){
        return num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3); 
    }
    
    int min(int num1,int num2,int num3){
        return num1 < num2 ? (num1 < num3 ? num1 : num3) : (num2 < num3 ? num2 : num3);
    }
};
```
