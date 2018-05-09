分治，将大链表拆分成2个长度相等的小链表，递归处理，每次递归返回后，两个小链表已经有序，然后将2个小链表进行归并

每次将链表分成2个长度相等的链表时，需要找到中间节点，可以使用1个快指针和1个慢指针

如果考虑递归调用的函数栈帧，那么空间复杂度为O(n)，不考虑则空间复杂度为O(1)

递归是“从上往下”的思想，也可以[“从下往上”](https://leetcode.com/problems/sort-list/discuss/46712/Bottom-to-up(not-recurring)-with-o(1)-space-complextity-and-o(nlgn)-time-complextity)，避免函数栈帧的开销

“从下往上”的代码：

```c++
/**
 * Merge sort use bottom-up policy, 
 * so Space Complexity is O(1)
 * Time Complexity is O(NlgN)
 * stable sort
*/
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(!head || !(head->next)) return head;
        
        //get the linked list's length
        ListNode* cur = head;
        int length = 0;
        while(cur){
            length++;
            cur = cur->next;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *left, *right, *tail;
        for(int step = 1; step < length; step <<= 1){
            cur = dummy.next;
            tail = &dummy;
            while(cur){
                left = cur;
                right = split(left, step);
                cur = split(right,step);
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }
private:
    /**
     * Divide the linked list into two lists,
     * while the first list contains first n ndoes
     * return the second list's head
     */
    ListNode* split(ListNode *head, int n){
        //if(!head) return NULL;
        for(int i = 1; head && i < n; i++) head = head->next;
        
        if(!head) return NULL;
        ListNode *second = head->next;
        head->next = NULL;
        return second;
    }
    /**
      * merge the two sorted linked list l1 and l2,
      * then append the merged sorted linked list to the node head
      * return the tail of the merged sorted linked list
     */
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
        ListNode *cur = head;
        while(l1 && l2){
            if(l1->val > l2->val){
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
            else{
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
        }
        cur->next = (l1 ? l1 : l2);
        while(cur->next) cur = cur->next;
        return cur;
    }
};
```

