/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        
        if(root->left && root->right)
            root->left->next = root->right;
        
        if(root->right && root->next && root->next->left)
            root->right->next = root->next->left;
        
        if(root->left)
            connect(root->left);
        if(root->right)
            connect(root->right);
            
    }
};