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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n <= 0)  return head;
        ListNode *prev = head,*behind = head;
        n = n + 1;//移动到倒数第n个节点的前一个节点
        while(n && prev){
            prev = prev->next;
            n--;
        }
        if(n){
            if(n > 1)   return head;    //n太大，直接返回
            //删除的是头节点
            behind = head;
            head = head->next;
            delete behind;
            return head;
        }
        while(prev){
            prev = prev->next;
            behind = behind->next;
        }
        ListNode *tp = behind->next->next;
        delete behind->next ;
        behind->next = tp;
        return head;
    }
};