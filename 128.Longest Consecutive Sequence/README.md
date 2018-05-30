## 题目

给定一个未排序的整数数组，找出最长连续序列的长度

要求算法的时间复杂度为 O(n)

示例:

```
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
```

## 解答

### 方法一：排序

先排序，排序完成后遍历一遍数组就能找出最长连续序列

```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0,sz = nums.size();
        for(int i = 0;i < sz;i++){
            int j = i,len = 1;
            while(j + 1 < sz){
                if(nums[j + 1] == nums[j] + 1)  len++;
                else if(nums[j + 1] != nums[j]) break;
                j++;
            }
            if(len > res)   res = len;
            i = j; //j + 1已经不连续，所以i再++就到了第一个不连续的位置
        }
        return res;
    }
};
```

* **时间复杂度**：O(nlogn)（accept，但不符合要求）
* **空间复杂度**：O(1)

### 方法二：hash表

[参考](https://www.youtube.com/watch?v=rc2QdQ7U78I)

使用一个hash表，key表示数，value表示以key为边界的连续序列的长度，很显然，当插入一个数字num时：

* 如果num已经存在hash表中，那么以前已经处理过，那么忽略
* 否则，又分为几种情况：
    - 如果num-1在hash表中，表明num刚好和num-1结尾的序列相连，因此组成一个新的最大连续序列，此时更新区间左边界和右边界（即num）hash表项的value，即最大连续序列的长度
    - 如果num+1在hash表中，表明num刚好和num+1开头的序列相连，因此组成一个新的最大连续序列，此时更新区间左边界（即num）和右边界hash表项的value，即最大连续序列的长度
    - 如果num-1和num+1都在hash表中，说明num将两个连续序列相连，因此更新左边区间左边界hash项的value，以及右区间右边界hash项的value

每次得到一个新的连续序列时，与结果判定，如果更大，那么更新结果。下图为[1,2,3,6,5,4]的示例：

<div align="center"> <img src="../img/128.png"/> </div>

* **时间复杂度**：O(n)
* **空间复杂度**：O(n)