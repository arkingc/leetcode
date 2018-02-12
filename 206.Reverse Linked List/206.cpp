/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
	迭代版
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head,*prev = NULL,*next;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};

/*
	递归版
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* p = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return p;
    }
};