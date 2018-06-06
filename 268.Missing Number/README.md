## 题目

给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

```
输入: [3,0,1]
输出: 2
```

示例 2:

```
输入: [9,6,4,2,3,5,7,0,1]
输出: 8
```

说明:

你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

## 解答

### 方法一：排序

将每个数交换到下标i+1的位置，最后遍历一遍数组，如果某个下标的元素，不等于该下标加1，那么缺失的数就是这个下标加1，如果所有位置的元素都等于下标加1，那么缺失0：

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            while(nums[i] != i + 1){
                if(nums[i] != 0 && nums[nums[i] - 1] != nums[i])
                    swap(nums[i],nums[nums[i] - 1]);
                else
                    break;
            }
        }
        for(int i = 0;i < nums.size();i++)
            if(nums[i] != i + 1)
                return i + 1;
        return 0;
    }
};
```

### 方法二：高斯公式

求0\~n的和，然后计算数组中所有元素的和，相减就是缺失的数

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int exceptSum = nums.size() * (nums.size() + 1) / 2;
        int actualSum = 0;
        for(int e : nums)   actualSum += e;
        return exceptSum - actualSum;
    }
};
```

这个方法在数字量大的时候感觉会溢出

### 方式三：异或

将0\~n异或，然后与所有数组中的元素异或，因为两个相同的数异或为0，那么最后会剩下缺失的那个数：

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for(int i = 0;i < nums.size();i++)
            missing ^= i ^ nums[i];
        return missing;
    }
};
```