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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int currLevel = 0,nextLevel = 0;
        deque<TreeNode*> dq;
        vector<vector<int>> res;
        
        if(root){
            dq.push_back(root);
            currLevel++;
        }
        
        vector<int> tp;
        while(!dq.empty()){
            if(currLevel){
                TreeNode *nd = dq.front();
                tp.push_back(nd->val);
                if(nd->left){
                    dq.push_back(nd->left);
                    nextLevel++;
                }
                if(nd->right){
                    dq.push_back(nd->right);
                    nextLevel++;
                }
                dq.pop_front();
                --currLevel;
            }
            if(currLevel == 0){
                currLevel = nextLevel;
                nextLevel = 0;
                res.push_back(tp);
                tp.clear();
            }
        }
        
        return res;
    }
};