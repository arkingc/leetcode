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
    bool isPalindrome(ListNode* head) {
        if(!head)   return true;
        
        ListNode *b = head,*e = NULL;
        return isPalindrome(head,&b,&e);
    }
    
private:
    bool isPalindrome(ListNode* node,ListNode **b,ListNode **e){       
        if(node->next)
            if(!isPalindrome(node->next,b,e))
                return false;
        
        if(*b == *e)    
            return true;
        *e = node;
        if((*b)->val == (*e)->val){
            (*b) = (*b)->next;
            return true;
        }
        else
            return false;
    }
};