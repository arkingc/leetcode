/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        int count = 0;
        while(p) {
            count++;
            p = p->next;
        }
        
        return sortedListToBSTCore(count,&head);
    }
private:
    TreeNode* sortedListToBSTCore(int count,ListNode** curr){
        if(count <= 0)  return NULL;
        
        TreeNode *root = new TreeNode(0);
        root->left = sortedListToBSTCore(count / 2,curr);
        root->val = (*curr)->val;
        (*curr) = (*curr)->next;
        root->right = sortedListToBSTCore(count - count / 2 - 1,curr);
        
        return root;
    }
};