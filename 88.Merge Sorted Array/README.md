## 题目

给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

* 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
* 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例:

```
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
```

## 解答

如果从前往后合并，那么可能会覆盖nums1中还未合并的元素，因此从后往前合并。

使用3个变量，end1指向nums1中需要合并的尾元素的位置，end2指向nums2中需要合并的尾元素的位置，end指向nums1的末尾。每次从end1和end2指向元素中选出较大者，插入end位置：

```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.empty() || nums2.empty() || m < 0 || n < 0)  return ;
        
        int end1 = m - 1,end2 = n - 1,end = nums1.size() - 1;
        while(end1 >= 0 && end2 >= 0){
            if(nums1[end1] >= nums2[end2])
                nums1[end--] = nums1[end1--];
            else
                nums1[end--] = nums2[end2--];
        }
        
        while(end2 >= 0)
            nums1[end--] = nums2[end2--];
    }
};
```