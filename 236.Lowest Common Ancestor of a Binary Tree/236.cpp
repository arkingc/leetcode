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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q)   return NULL;
        if(p == q)  return p;
        
        vector<vector<TreeNode*>> paths;
        vector<TreeNode*> path;
        
        preOrderTraversal(root,p,q,paths,path);
        
        if(paths.size() != 2)   return NULL;
        
        int i = 0,j = 0;
        while(paths[0][i + 1] == paths[1][j + 1])   i++,j++;
        
        return paths[0][i];
    }
private:
    void preOrderTraversal(TreeNode *root,TreeNode *p,TreeNode *q,
                           vector<vector<TreeNode*>> &paths,vector<TreeNode*> &path)
    {
        if(!root)   return;
        
        path.push_back(root);
        if(root == p)   paths.push_back(path);
        else if(root == q)  paths.push_back(path);
        if(root->left)  preOrderTraversal(root->left,p,q,paths,path);
        if(root->right) preOrderTraversal(root->right,p,q,paths,path);
        path.pop_back();
    }
};