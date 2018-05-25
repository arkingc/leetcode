## 题目

给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 

示例 1:

```
nums1 = [1, 3]
nums2 = [2]

中位数是 2.0
```

示例 2:

```
nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5
```

## 解答

### 1）方法一（不满足要求）

使用一个辅助数组，使用归并排序的合并方法将两个数组合并，排成一个按序排序的数组，然后求中值：

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int idx1 = 0,idx2 = 0,idx = 0,sz1 = nums1.size(),sz2 = nums2.size();
        vector<int> nums(sz1 + sz2,0);
        while(idx1 != sz1 && idx2 != sz2){
            if(nums1[idx1] < nums2[idx2])   nums[idx++] = nums1[idx1++];
            else nums[idx++] = nums2[idx2++];
        }
        while(idx1 != sz1)  nums[idx++] = nums1[idx1++];
        while(idx2 != sz2)  nums[idx++] = nums2[idx2++];
        
        if((sz1 + sz2) % 2 == 0)
            return (double)(nums[(sz1 + sz2 - 1) / 2] + nums[(sz1 + sz2) / 2]) / 2;
        else
            return nums[(sz1 + sz2) / 2];
    }
};
```

* **时间复杂度**：O(m + n)
* **空间复杂度**：O(m + n)

时间复杂度不满足题目要求，但是这种方法也能accept


### 2）方法二（不满足要求）

还是使用归并排序合并的思想，但是不使用辅助数组，根据两个数组的大小判断中值的下标，然后归并过程中递增下标，直到到达中值的下标。这样可以避免使用额外空间

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int idx1 = 0,idx2 = 0,sz1 = nums1.size(),sz2 = nums2.size();
        int end1 = (sz1 + sz2 - 1) / 2, end2 = (sz1 + sz2) % 2 ? -1 : (sz1 + sz2) / 2,begin = 0;
        int num1,num2;
        
        while(idx1 != sz1 && idx2 != sz2){
            if(begin == end1){
                num1 = nums1[idx1] < nums2[idx2] ? nums1[idx1] : nums2[idx2];
                if(end2 == -1)   return num1;
            }
            if(begin == end2){
                num2 = nums1[idx1] < nums2[idx2] ? nums1[idx1] : nums2[idx2];
                return (double)(num1 + num2) / 2;
            }
            if(nums1[idx1] < nums2[idx2])   idx1++;
            else    idx2++;
            begin++;
        }
        
        while(idx1 != sz1){
            if(begin == end1){
                num1 = nums1[idx1];
                if(end2 == -1)   return num1;
            }
            if(begin == end2){
                num2 = nums1[idx1];
                return (double)(num1 + num2) / 2;
            }
            idx1++;
            begin++;
        }
        while(idx2 != sz2){
            if(begin == end1){
                num1 = nums2[idx2];
                if(end2 == -1)   return num1;
            }
            if(begin == end2){
                num2 = nums2[idx2];
                return (double)(num1 + num2) / 2;
            }
            idx2++;
            begin++;
        }
        
        return 0;//nums1和nums2都为空
    }
};
```

* **时间复杂度**：O(m + n)
* **空间复杂度**：O(1)

时间复杂度不满足题目要求，但是这种方法也能accept

### 3）方法三（满足要求）

要求O(log(m+n))的时间复杂度，那么必须使用二分法，那么如何进行二分？考虑将数组num1分为2部分```[part1,part3]```，将数组num2分为2部分```[part2,part3]```，然后假设part1包含sz1个元素，part2包含sz2个元素。那么我们肯定是要找到part1和part2，使得：

```sz1+sz2 = len/2，len为两个数组总长```

可以以len/2为长度总和，以part1为基准：

* 当part1变大时，sz1扩大，那么sz2必须减小，因此part2要减小
* 当part1变小时，sz1减小，那么sz2必须扩大，因此part2要扩大

现在问题是根据什么标准来扩大或减小part1？这里设4个变量：

1. part1中最右边的元素（即part1最大的元素）为l1
2. part3中最左边的元素（即part3最小的元素）为r1
3. part2中最右边的元素（即part2最大的元素）为l2
4. part4中最左边的元素（即part4最小的元素）为r2

现在大小已经满足要求，由于part1和part2必须为数组nums1和nums2组成数组的前半部分，那么必须满足：

```
l1 <= r1（已经满足）
l1 <= r2
l2 <= r1
l2 <= r2（已经满足）
```

因此，可以根据中间两个条件是否满足来扩大或减小part1

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int sz = nums1.size() + nums2.size();
        int sz1l = 0,sz1r = nums1.size();
        int sz1 = 0,sz2 = 0;
        while(sz1 <= nums1.size()){
            sz1 = (sz1l + sz1r) / 2;
            sz2 = sz / 2 - sz1; 
            int l1 = sz1 == 0 ? INT_MIN : nums1[sz1 - 1];
            int r1 = sz1 == nums1.size() ? INT_MAX : nums1[sz1];
            int l2 = sz2 == 0 ? INT_MIN : nums2[sz2 - 1];
            int r2 = sz2 == nums2.size() ? INT_MAX : nums2[sz2];
            if(l1 > r2)
                sz1r = sz1 - 1;
            else if(l2  > r1)
                sz1l = sz1 + 1;
            else{
                if(sz % 2 == 0){
                    l1 = l1 > l2 ? l1 : l2;
                    r1 = r1 < r2 ? r1 : r2;
                    return (double)(l1 + r1) / 2;
                }
                else{
                    r1 = r1 < r2 ? r1 : r2;
                    return r1;
                }
            }
                
        }
        
        return -1;
    }
};
```