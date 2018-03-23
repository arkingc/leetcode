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
    ListNode* swapPairs(ListNode* head) {
        ListNode *prev = nullptr,*curr = head;
        
        while(curr && curr->next){
            if(prev){
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = curr;
            }
            else{
                prev = curr->next;
                curr->next = prev->next;
                prev->next = curr;
                head = prev;
            }
            
            prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};