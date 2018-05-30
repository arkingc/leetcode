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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0,r = nums.size() - 1;
        return sortedArrayToBSTCore(nums,l,r);
    }
public:
    TreeNode* sortedArrayToBSTCore(vector<int> &nums,int l,int r){
        if(l > r)   return NULL;
        
        int mid = (l + r) >> 1;
        TreeNode *root = new TreeNode(nums[mid]);
        if(l < r){
            root->left = sortedArrayToBSTCore(nums,l,mid - 1);
            root->right = sortedArrayToBSTCore(nums,mid + 1,r);
        }
        
        return root;
    }
};