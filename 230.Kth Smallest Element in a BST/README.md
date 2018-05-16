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
```

## 递归版

```c++
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root || k < 0)   return -1;
        
        int res;
        preOrderTraversal(root,k,res);
        
        return res;
    }
private:
    void preOrderTraversal(TreeNode *node,int &k,int &res){
        if(!node)   return;
        
        preOrderTraversal(node->left,k,res);
        if(k == 0)  return;
        if(--k == 0)  res = node->val;
        else    preOrderTraversal(node->right,k,res);
    }
};
```

## 迭代版

```c++
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root || k < 0)  return -1;
        
        stack<TreeNode*> s;
        TreeNode *curr = root;
        while(curr || !s.empty()){
            if(curr){
                s.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode *nd = s.top();
                if(k == 1)  return nd->val;
                s.pop();k--;
                curr = nd->right;
            }
        }
        
        return -1;//k大于BST的节点总数
    }
};
```