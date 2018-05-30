## 题目

给定一个二叉树，检查它是否是镜像对称的

例如，二叉树 [1,2,2,3,4,4,3] 是对称的

```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

```
    1
   / \
  2   2
   \   \
   3    3
```

说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分

## 解答

### 方法一：递归

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
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        
        TreeNode *nd1 = root->left,*nd2 = root->right;
        return equalNode(nd1,nd2);
    }
    
private:
    bool equalNode(TreeNode* nd1,TreeNode* nd2){
        if(!nd1)    return !nd2;
        if(!nd2)    return false;
        
        if(nd1->val == nd2->val)
            return equalNode(nd1->left,nd2->right) && equalNode(nd1->right,nd2->left);
        return false;
    }
};
```

### 方法二：迭代

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
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        while(!s.empty()){
            TreeNode *nd1 = s.top();
            s.pop();
            TreeNode *nd2 = s.top();
            s.pop();
            if(!nd1 && !nd2)    continue;
            else if(!nd1 && nd2)    return false;
            else if(nd1 && !nd2)    return false;
            else if(nd1->val != nd2->val)   return false;
            s.push(nd1->left),s.push(nd2->right);
            s.push(nd1->right),s.push(nd2->left);
        }
        
        return true;
    }
};
```