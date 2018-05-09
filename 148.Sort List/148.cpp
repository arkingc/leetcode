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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)    return head;
        
        ListNode *middle = getMiddle(head); //找出中间节点需要O(n)的时间
        ListNode *head2 = middle->next;
        middle->next = NULL;
        
        //每一轮归并需要O(n)的时间，需要归并log(n)轮
        return merge(sortList(head),sortList(head2));
    }
    
private:
    //case1：空链表，返回空
    //case2：n个节点，n为奇数，返回中间的节点
    //case3：n个节点，n为偶数，返回左半部最后一个节点
    ListNode* getMiddle(ListNode* head){
        if(!head)   return head;
        
        ListNode *slow = head,*quick = head;
        while(quick->next && quick->next->next){
            quick = quick->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode dummy(0);
        ListNode *curr = &dummy;
        
        while(head1 && head2){
            if(head1->val <= head2->val){
                curr->next = head1;
                head1 = head1->next;
            }
            else{
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        if(!head1)  curr->next = head2;
        else        curr->next = head1;
        return dummy.next;
    }
};