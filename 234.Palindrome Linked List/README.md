## 题目

请判断一个链表是否为回文链表。

示例 1:

```
输入: 1->2
输出: false
```

示例 2:

```
输入: 1->2->2->1
输出: true
```

进阶：

你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

## 解答

使用两个指针b和e，b指向链表的头节点，e指向链表的尾节点，如果b和e的值相等，那么b指向下一个节点，e指向前一个节点，直到b和e指向相同节点。关键是链表单向，因此使用递归来设置e：

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
```