## 题目

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

```
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
```

## 解答

要平衡，那么左右子树节点首先必须相等，因此最开始选择数组中间的元素作为根节点，数组左边的元素用来构造左子树，右边的元素用来构造右子树。由于数组有序，因此满足BST的性质。选择左边数组的中间元素作为左子节点，右边数组的中间元素作为右子节点，从而又保证了以左右子节点为根节点的树的左子树和右子树的元素相等。这样递归构造，最终可以保证平衡：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0,r = nums.size() - 1;
        return sortedArrayToBSTCore(nums,l,r);
    }
public:
    TreeNode* sortedArrayToBSTCore(vector<int> &nums,int l,int r){
        if(l > r)   return NULL;
        
        int mid = (l + r) >> 1;
        TreeNode *root = new TreeNode(nums[mid]);
        if(l < r){
            root->left = sortedArrayToBSTCore(nums,l,mid - 1);
            root->right = sortedArrayToBSTCore(nums,mid + 1,r);
        }
        
        return root;
    }
};
```