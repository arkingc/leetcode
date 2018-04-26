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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> dq;
        stack<TreeNode*> st;
        bool leftToright = true;
        
        if(root)    dq.push_back(root);
        
        vector<int> tp;
        while(!dq.empty()){
            TreeNode *nd = dq.front();
            dq.pop_front();
            tp.push_back(nd->val);
            if(leftToright){
                if(nd->left)    st.push(nd->left);
                if(nd->right)   st.push(nd->right);
            }
            else{
                if(nd->right)   st.push(nd->right);
                if(nd->left)    st.push(nd->left);
            }

            if(dq.empty()){
                res.push_back(tp);
                tp.clear();
                while(!st.empty()){
                    dq.push_back(st.top());
                    st.pop();
                }
                leftToright = !leftToright;
            }
        }
        
        return res;
    }
};