## 题目

给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例:

```
输入: [5,2,6,1]
输出: [2,1,1,0] 
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.
```

## 解答

### 1）归并(分治)

其实就是类似[求逆序对](https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)的方法，不过求逆序对这个题是求出逆序对的总数即可，但是这里实际是求数组中每个元素和其后元素的数构成多少个逆序对，所以会复杂一些，但是方法一样

假设有2个数组num1（假设下标为l1-r1）和num2（假设下标为l2-r2），满足下列性质：

* num1和num2已经按照降序排好序
* l1 <= r1 < l2 <= r2

因为num1中的每个元素都在num2的前面，因此很好统计有多少个逆序对，归并过程如下：

* 对于num1中的元素m和num2中的元素n，有：
    - 如果m大于n，那么m元素的逆序对增加的数量为num2中n及n以后所有元素的数量，然后继续处理num1中m后方的元素
    - 如果m小于等于n，m及num1中m后方的元素，都不可能与n构成逆序对，因此处理num2中n后方的元素
* 上面的过程可以统计出逆序对，但是在该次归并后，下一次归并时，我们需要保证新的更大的数组依然满足降序的顺序，因此在统计逆序对的过程中需要进行归并排序
* 最后一个问题是，在统计逆序对的过程中，如果m比n大，那么需要增加m的逆序对的数量，但是在归并过程中，m的位置可能不断发生变化，同时数组中可能包含相同的值，即多个m，那么如何根据m定位到需要增加逆序对的位置？答案是使用下标，在归并和排序的过程中，使用的是一个下标数组idx，根据这个数组可以定位到元素在最初数组中的位置，同时，即使不断移动，也能索引到其值

```c++
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> idx;
        for(int i = 0;i < nums.size();i++)  idx.push_back(i);
        vector<int> res(nums.size(),0);
        vector<int> tmp(nums.size(),0);
        countSmallerCore(nums,idx,tmp,res,0,nums.size() - 1);
        return res;
    }
private:
    void countSmallerCore(vector<int> &nums,vector<int> &idx,vector<int> &tmp,vector<int> &res,int l,int r){
        if(l >= r)  return;

        int mid = (l + r) >> 1;
        countSmallerCore(nums,idx,tmp,res,l,mid);
        countSmallerCore(nums,idx,tmp,res,mid + 1,r);
        merge(nums,idx,tmp,res,l,mid,mid + 1,r);
    }

    void merge(vector<int> &nums,vector<int> &idx,vector<int> &tmp,vector<int> &res,int l1,int r1,int l2,int r2){
        int p1 = l1,p2 = l2,p = l1;
        while(p1 <= r1 && p2 <= r2){
            if(nums[idx[p1]] > nums[idx[p2]]){
                res[idx[p1]] += r2 - p2 + 1;
                tmp[p++] = idx[p1++];
            }
            else
                tmp[p++] = idx[p2++];
        }
        while(p1 <= r1) tmp[p++] = idx[p1++];
        while(p2 <= r2) tmp[p++] = idx[p2++];

        p = l1;
        while(p <= r2){
            idx[p] = tmp[p];
            p++;
        }
    }

};
```

### 2）树状数组

* [树状数组(Binary Index Tree)介绍](https://www.youtube.com/watch?v=WbafSgetDDk)
* [树状数组的解法](https://www.youtube.com/watch?v=2SVLYsq5W8M)

```c++
// Author: Huahua
// Runnning time: 32 ms
// Time complexity: O(nlogn)
// Space complexity: O(k), k is the number unique elements
class FenwickTree {    
public:
    FenwickTree(int n): sums_(n + 1, 0) {}
    
    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) const {        
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
private:
    static inline int lowbit(int x) { return x & (-x); }
    vector<int> sums_;
};
 
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // Sort the unique numbers
        set<int> sorted(nums.begin(), nums.end());
        // Map the number to its rank
        unordered_map<int, int> ranks;
        int rank = 0;
        for (const int num : sorted)
            ranks[num] = ++rank;
        
        vector<int> ans;
        FenwickTree tree(ranks.size());
        // Scan the numbers in reversed order
        for (int i = nums.size() - 1; i >= 0; --i) {
            // Chechk how many numbers are smaller than the current number.
            ans.push_back(tree.query(ranks[nums[i]] - 1));
            // Increse the count of the rank of current number.
            tree.update(ranks[nums[i]], 1);
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
