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