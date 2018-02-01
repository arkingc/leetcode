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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA,*pB = headB;
        
        if(!pA || !pB)  return NULL;
        
        while(pA || pB){
            if(pA == pB)    return pA;
            else{
                if(!pA) {
                    pA = headB;
                    pB = pB -> next;
                }
                else if(!pB) {
                    pB = headA;
                    pA = pA -> next;
                }
                else {
                    pA = pA -> next;
                    pB = pB -> next;
                }
            }
        }
        
        return NULL;
    }
};