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
    bool isValidBST(TreeNode* root) {
        int *prev = nullptr;
        return isValidBST(root,&prev);
    }
    
    bool isValidBST(TreeNode* node,int **pprev){
        if(!node)
            return true;
        
        bool res = isValidBST(node->left,pprev);
        
        if(*pprev)
            res = res && (node->val > **pprev);
        *pprev = &(node->val);
        
        res = res && isValidBST(node->right,pprev);
        
        return res;
    }
};