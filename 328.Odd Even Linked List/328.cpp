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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)    return head;
        
        ListNode *oddlist = head,*evenlist = head->next,*p1 = head,*p2 = NULL;
        int odd = 1;
        while(p1->next){
            ListNode *tp = p1->next;
            p1->next = tp->next;
            p2 = p1;
            p1 = tp;
            odd = 1 - odd;
        }
        
        if(odd)//此时p1是奇数链表的尾节点
            p1->next = evenlist;
        else//此时p2是奇数链表的尾节点，因为odd不为1，说明上面while循环体至少被执行1次，所以p2不为NULL
            p2->next = evenlist;
        return oddlist;
    }
};