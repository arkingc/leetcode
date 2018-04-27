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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
            return nullptr;
        return buildTree(preorder,0,preorder.size() - 1,inorder,0,inorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int> &preorder,int b1,int e1,vector<int> &inorder,int b2,int e2)
    {
        if(e1 < b1 || e2 < b2 || e1 - b1 != e2 - b2)  return nullptr;
            
        int rootval = preorder[b1];
        int count = 0;
        for(int i = b2;i <= e2;i++){
            if(inorder[i] != rootval)  count++;
            else    break;
        }
        
        if(count == e2 - b2 + 1)  return nullptr;
        
        TreeNode *root = new TreeNode(rootval);
        root->left = buildTree(preorder,b1 + 1,b1 + count,inorder,b2,b2 + count - 1);
        root->right = buildTree(preorder,b1 + count + 1,e1,inorder,b2 + count + 1,e2);
        
        return root;
    }
};