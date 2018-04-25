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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> st;
        if(root)
            st.push(root);
        
        TreeNode *curr = root;
        while(curr || !st.empty()){
            if(curr){
                if(curr->left)
                    st.push(curr->left);
                curr = curr->left;
            }
            else{
                TreeNode *nd = st.top();
                st.pop();
                res.push_back(nd->val);
                if(nd->right){
                    curr = nd -> right;
                    st.push(curr);
                }
            }
        }
        
        return res;
    }
};