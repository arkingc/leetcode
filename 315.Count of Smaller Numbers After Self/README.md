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

### 2）BST

假设从数组右边往左构建BST，每当遍历到一个元素时，其右边节点已经构成了一棵BST，对于当前节点，如果能在将其插入BST的过程中同时得到BST中小于该元素的节点个数，那么每个元素就能实现O(logn)的查找，总的时间复杂度就是O(nlogn)

为了能够在BST中快速得到比新插入元素小的节点个数，肯定需要在节点中维护除节点值以外的其它信息。因为数组中可能包含相同元素，那么BST节点中添加一个`count`变量统计相同元素的个数，那么再添加一个`left_count`变量表示BST中比当前节点值小的节点总数（**这种假设是一种全局性质**），假设这样行的通，那么只要找到新节点插入点的父节点，那么就可以根据父节点判断比新值小的元素有多少个

但是这样行不通，因为在插入节点时，需要更新BST中已有节点的`left_count`，如果`left_count`表示BST中比当前节点值小的节点总数，那么无法实现O(logn)的查找，考虑如下例子：

```
       a
      / \
     b   c 
```


* 如果新节点比a小，如果`left_count`表示BST中比当前节点值小的节点总数，那么在新节点插入时，需要递增a节点的`left_count`
* 如果新节点比a大，a节点的`left_count`不变，继续往a节点的右子树处理

注意，问题出在新节点比a小时！此时只能更新a，如果`left_count`表示BST中比当前节点值小的节点总数，那么所有a节点右子树中的节点都应该递增其`left_count`

那么到底应该赋予`left_count`什么样的意义？现在不管a节点的左子树和右子树长什么样，并且假设a是BST中任意节点。每当一个节点需要插入a节点的左边时，比a节点小的节点都加1，这是肯定没问题的。所以我们**只能保证一种局部性质**，即**`left_count`表示该节点左子树的节点总数**

那么如果`left_count`表示该节点左子树的节点总数，有没有办法在插入一个节点时获取整棵BST中比新节点小的节点总是？答案是肯定的，从根节点开始遍历，查找新节点的插入位置：

* 如果新节点大于某个节点a，那么小于新节点的节点个数就增加`a->left_count+a->count`
* 如果新节点等于某个节点a，那么小于新节点的节点个数就增加`a->left_count`
* 如果新节点小于某个节点a，此时只能知道新节点在a的左子树中，但是无法知道a的左子树中有多少节点小于新节点，所以暂时无法得出应该增加多少，因此增加`0`

```c++
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() <= 0)    return vector<int>();
        
        vector<int> res;
        BSTNode *root = new BSTNode(nums.back());
        res.push_back(0);
        for(int i = nums.size() - 2;i >= 0;i--)
            res.push_back(insertBSTNode(root,nums[i]));
        
        delete root;
    
        reverse(res.begin(),res.end());
        
        return res;    
    }
private:
    struct BSTNode{
        int val;        //节点的值
        int count;      //相同值的个数
        int left_count; //左子树节点的个数
        BSTNode *left;
        BSTNode *right;
        BSTNode(int v) : val(v) , count(1) , left_count(0) , left(NULL) , right(NULL) {}
        ~BSTNode() {delete left;delete right;}
    };

    int insertBSTNode(BSTNode *root,int val){
        int res = 0;
        BSTNode *p = root,*pp;
        while(p){
            if(val < p->val){
                (p->left_count)++;
                res += 0;
                pp = p;
                p = p->left;
            }
            else if(val > p->val){
                res += p->count + p->left_count;
                pp = p;
                p = p->right;
            }
            else{
                (p->count)++;
                res += p->left_count;
                break;
            }
        }
        BSTNode *node = p;
        if(!p){ //说明不是一个以前出现过的值，因此需要插入
            node = new BSTNode(val);
            if(val < pp->val)   pp->left = node;
            else    pp->right = node;
        }
        return res;
    }
};
```

### 3）树状数组

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
