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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSum(root,res);
        
        return res;
    }
private:
    int maxPathSum(TreeNode* root,int &res) {
        if(!root)   return 0;
        
        int max;
        int leftMax = maxPathSum(root->left,res);
        int rightMax = maxPathSum(root->right,res);
        if(leftMax <= 0 && rightMax <= 0)   //两边都小于等于0
            max = root->val;
        else if(leftMax <= 0 || rightMax <= 0) //有一边大于0，另一边小于等于0
            max = leftMax > rightMax ? leftMax + root->val : rightMax + root->val;
        else //两边都大于0
            max = leftMax + rightMax + root->val;
        
        if(max > res)   res = max;
        
        if(leftMax <= 0 && rightMax <= 0)   //两边都小于等于0
            return root->val;
        else    //至少有一边大于0
            return leftMax > rightMax ? leftMax + root->val : rightMax + root->val;
    }
};