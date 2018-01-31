/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode **curr = &head,*tp;

        while(*curr){//当前节点不为NULL
            if((*curr)->next && (*curr)->val == (*curr)->next->val){
                tp = (*curr)->next;
                (*curr)->next = tp->next;
                tp->next = NULL;
            }
            else
                curr = &((*curr)->next);
        }
        
        return head;
    }
};