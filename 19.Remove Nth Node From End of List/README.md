## 题目

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

```
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
```

说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

## 解答

### 方法一：双指针

使用两个指针，一个指针先走n+1步，然后两个指针一起走，这样当先走的指针为NULL时，后走的指针指向倒数第n+1个节点，然后删除倒数第n个节点即可：

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
```

### 方法二：递归

使用递归找到倒数第n+1个节点，然后删除倒数第n个节点：

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n <= 0)  return head;
        removeNthFromEnd(head,&n);
        if(n == 0){
            ListNode *tp = head;
            head = head->next;
            delete tp;
        }
        return head;
    }
private:
    void removeNthFromEnd(ListNode* head,int *n){
        if(!head)   return;
        
        removeNthFromEnd(head->next,n);
        
        if((*n)-- == 0){
            ListNode *tp = head->next;
            head->next = tp->next;
            delete tp;
            return;
        }
    }
};
```