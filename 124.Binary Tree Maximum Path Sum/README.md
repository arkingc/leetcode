## 题目

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不需要经过根节点。

示例 1:

```
输入: [1,2,3]

       1
      / \
     2   3

输出: 6
```

示例 2:

```
输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42
```

## 解答

对于一棵root为根节点的树，假设其左子树(含左子节点)的最大路径为maxLeft，右子树(含右子节点)的最大路径为maxRight：

* 如果maxLeft小于等于0，那么不含入左子节点（也就是说将路径从左子节点处切断），可以得到一个更大的路径
* 如果maxRight小于等于0，那么不含入右子节点（也就是说将路径从右子节点处切断），可以得到一个更大的路径
* 如果两者都大于0，那么连通左右子树可以得到一个更大的路径

因此，根据上面几种情况，可以得到一个“局部最大”的路径。局部最大是因为这个路径包含了root节点。但是全局最大的路径不一定包含root节点。因此需要一个全局最大路径的变量res，如果res小于这个局部最大路径，那么更新res

那么maxLeft和maxRight应该怎么得到，也就是函数应该返回什么？注意上面对maxLeft和maxRight的描述中，这两个都包含了左右子树的根节点，因此，返回值不是res。那么是不是这个局部最大的路径？也不是，因为局部最大的路径可能连通了左右子树，比如上面示例2中以20为根节点的树。因此，这个返回值是一个单边路径，也就是说，如果maxLeft和maxRight都小于0，那么只返回根节点的值（路径只包含 根节点），否则，返回maxLeft和maxRight中较大者加上根节点的值

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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSum(root,res);
        
        return res;
    }
private:
    int maxPathSum(TreeNode* root,int &res) {
        if(!root)   return 0;
        
        int max;
        int leftMax = maxPathSum(root->left,res);
        int rightMax = maxPathSum(root->right,res);
        if(leftMax <= 0 && rightMax <= 0)   //两边都小于等于0
            max = root->val;
        else if(leftMax <= 0 || rightMax <= 0) //有一边大于0，另一边小于等于0
            max = leftMax > rightMax ? leftMax + root->val : rightMax + root->val;
        else //两边都大于0
            max = leftMax + rightMax + root->val;
        
        if(max > res)   res = max;
        
        if(leftMax <= 0 && rightMax <= 0)   //两边都小于等于0
            return root->val;
        else    //至少有一边大于0
            return leftMax > rightMax ? leftMax + root->val : rightMax + root->val;
    }
};
```