## 题目

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

```
输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
```

说明:

假设你总是可以到达数组的最后一个位置。

## 解答

### 1）动态规划

假设现在位于位置`i`，并且可以跳跃最多`nums[i]`步，那么可以选择跳`1,2,3,...,nums[i]`步，设`dp[i]`表示从位置`i`到达终点的最少步数，那么`dp[i] = min{dp[i + 1] + 1,dp[i + 2] + 1,dp[i + 3] + 1,...,dp[i + nums[i]] + 1}`，我们最终就是要求得`dp[0]`，因为`dp[0]`取决于`dp[1],dp[2],...,`所以从后往前求，并且维护`dp`数组，防止求重复子问题

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        
        vector<int> dp(sz,INT_MAX);
        dp[sz - 1] = 0;
        
        for(int i = sz - 2;i >= 0;i--){
            if(nums[i] >= sz - 1 - i)   dp[i] = 1;
            else{
                for(int j = 1;j <= nums[i];j++)
                    if(dp[i + j] != INT_MAX)//如果dp[i + j]等于INT_MAX，表明跳j步无法到达终点
                        dp[i] = min(dp[i],dp[i + j] + 1);
            }
        }
        
        return dp[0];
    }
};
```

* 时间复杂度：O(n^2)（最后一个例子会超时）

### 2）BFS

从起点开始，如果从该位置跳跃最大步数无法到达终点，那么将该位置能到达的点加入到队列，所有从起点能到达的点为一层，然后判断下一层的所有点是否能到达终点，如果不能，那么将下一层所有点能够到达的点加入到队列，从而产生新的一层。最终直到某一层存在能够到达终点的点

* 为了防止重复添加，使用一个标记数组`flags`，如果某个节点已经加入到队列，那么`flags`中这个节点标记为`1`，因此，最多只会向队列添加`n`个节点
* 还有一点需要注意。对于每个点，应该从该点所能跳跃的最大步开始尝试。对于点`i`，设该位置能跳跃的最大步为`nums[i]`，那么应该先尝试跳跃`nums[i]`步，如果不能到达终点，那么判断点`i + nums[i]`是否已经加入到队列中，如果没有则加入，**如果已经加入，那么停止尝试跳`nums[i] - 1,nums[i] - 2,...,1`步，因为如果从`i`跳`nums[i]`步不能到达终点，那么跳更小的步数肯定也不能到达。同时，如果`i + nums[i]`已经添加到了队列中，那么`i + nums[i] - 1,i + nums[i] - 2,...,i + 1`肯定也已经添加到了队列中**

* 时间复杂度：O(n)

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)    return 0;
        
        int target = nums.size() - 1,res = 0;
        deque<int> d;
        d.push_back(0);
        vector<int> flags(nums.size(),0);   //防止重复添加节点
        flags[0] = 1;
        
        while(!d.empty()){
            int level = d.size();   //这一层的节点数
            while(level--){
                int src = d.front();
                d.pop_front();
                for(int i = nums[src];i >= 1;i--){
                    if(src + i >= target)        
                        return ++res;
                    else if(flags[src + i] == 1)
                        break;
                    else {
                        d.push_back(src + i);
                        flags[src + i] = 1;
                    }
                }
            }
            res++;
        }
        
        return -1;//无法到达
    }
};
```
