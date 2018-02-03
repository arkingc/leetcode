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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tp,**curr = &head;

        while(*curr){
            if((*curr)->val == val){
                tp = *curr;
                *curr = (*curr) -> next;
                tp -> next = NULL;
                delete tp;
            }
            else
                curr = &((*curr) -> next);
        }

        return head;
    }
};