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