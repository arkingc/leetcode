## 题目

给定一个链表，判断链表中是否有环。

进阶：

你能否不使用额外空间解决此题？

## 解答

使用1个快指针和1个慢指针，如果存在环，2个指针必然在环内相遇

```c++
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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head,*fast = head;
        while(fast){
            if(fast->next){
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow)    return true;
            }
            else
                return false;
        }
        return false;
    }
};
```

