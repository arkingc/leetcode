## 题目

给定两个数组，写一个方法来计算它们的交集。

例如:


给定 `nums1 = [1, 2, 2, 1]`, `nums2 = [2, 2]`, 返回 `[2, 2]`.

注意：

* 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
* 我们可以不考虑输出结果的顺序。

跟进:

* 如果给定的数组已经排好序呢？你将如何优化你的算法？（**归并处理**）
* 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
* 如果nums2的元素存储在磁盘上，内存是有限的，你不能一次加载所有的元素到内存中，你该怎么办？（**哈希成多个小文件，小文件分治求交集**）

## 解答

使用一个hash表统计一个数组中每个数字出现的次数，然后遍历另外一个数组，如果某个数组出现在哈希表中则添加到结果中，由于可以包含重复数字，所以需要计数每个数字出现的次数：

```c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> countMap;
        
        vector<int> res;
        for(int num : nums1)  countMap[num]++;
        
        for(int num : nums2)
            if(countMap[num]-- > 0)
                res.push_back(num);
        
        return res;
    }
};
```