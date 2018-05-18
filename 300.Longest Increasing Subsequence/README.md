## 题目

给出一个整形数组，找出数组最长的升序序列（**序列不一定连续**）

## 解答

### 方法一

动态规划

n个元素的数组nums可以按照起始元素划分成n类子数组：第1类子数组以nums[0]为首元素，第2类子数组以nums[1]为首元素...，如果能找到每一类子数组中，最长的升序序列，那么数组nums的最长升序序列就是n类子数组中最长升序序列最长的那个。即，假设第i类子数组的最长升序序列的长度为fun(i)

那么 max{fun(1),fun(2),...,f(n)}就是答案

那么如何求fun(i)？以第1类子数组（首元素为num[0]的所有子数组）为例，既然nums[0]为首元素，要找到最长升序序列，下一个元素必定比nums[0]大，假设第一个大于nums[0]的元素为nums[j]，如果最长升序序列包含nums[j]，那么f(1) = 1+fun(j+1);否则，继续找到下一个比nums[0]大的元素nums[k]，如果最长升序序列包含nums[k]，那么f(1) = 1+fun(k+1);否则，...，因为nums[0]后任意一个比nums[0]大的元素都可能是最长升序序列的元素，所以要取这些结果中最大的一个

使用一个数组state保存每个fun(i)，因为以最后一个元素为首元素的子数组只有1个，即该元素本身，所以最长升序序列的长度为1，即fun(n) = 1，可以从后向前求解fun(n-1),fun(n-2),...,fun(1)

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())    return 0;
        
        vector<int> state(nums.size(),1);
        for(int i = nums.size() - 2;i >= 0;i--){
            for(int j = i + 1;j < nums.size();j++){
                if(nums[i] < nums[j] && state[i] < state[j] + 1)
                    state[i] = state[j] + 1;
            }
        }
        
        int max = 1;
        for(int e : state)
            if(e > max) max = e;
        
        return max;
    }
};
```

### 方法二

[参考](https://leetcode.com/problems/longest-increasing-subsequence/discuss/74855/Short-C++-STL-based-solution:-O(n-log-n)-time-O(1)-space-with-explanation)

使用一个数组S保存最长升序序列的状态，它始终保持升序，每个元素插入S中时，替换掉S中大于等于这个插入元素的第一个元素，如果插入的元素大于S的最后一个元素，那么扩展S

举个例子：

```
nums = [5,6,7,1,2,8,3,4,0,5,9]
```

当处理到7时，因为前3个元素升序，所以组成一个升序序列：

```
S = [5,6,7]
```

当处理1时，它终止了序列持续上升的趋势，可能会引导出一个新的更长的升序序列。因此替换掉大于等于它的第一个元素5：

```
S = [1,6,7]
```

接着处理2：

```
S = [1,2,7]
```

处理8时，需要扩展升序序列：

```
S = [1,2,7,8]
```

然后处理3：

```
S = [1,2,3,8]
```

处理4：

```
S = [1,2,3,4]
```

处理最后3个元素:

```
S = [0,2,3,4,5,9]
```

因为只需遍历1遍数组，并且每次更新S可以使用二分查找，所以时间复杂度为O(n\*logn)

因为只需遍历一遍数组，所以可以直接在nums的前部进行修改，作为S，从而不需要额外的空间

```c++
int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0)
        return nums.size();

    vector<int>::iterator m = nums.begin();  // m will mark the virtual "S.end()".
    for (int& val : nums) {
        //lower_bound使用二分查找，查找[nums.begin(),m)区间内第一个大于等于val的元素
        //返回相应迭代器
        auto it = lower_bound(nums.begin(), m, val);
        *it = val;
        if (it == m)
            m++;
    }
    
    return m - nums.begin();
}
```