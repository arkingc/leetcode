## 问题

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度

示例:

```
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
```

## 解答

### 方法一

假设链表个数为k，那么可以使用k个链表的头节点建立一个k个节点的最小堆，每次从堆中删除堆顶节点，然后将被删除的节点所在链表的下一个节点添加到堆中。没删除一个节点就将被删除的节点链入结果链表中

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
    struct Node{
        int idx;
        ListNode *node;
        Node(int i,ListNode *n) : node(n) , idx(i) {}
    };
    
    struct Compare{
        bool operator()(const Node &n1,const Node &n2){
            return n1.node->val > n2.node->val;
        } 
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz = lists.size();
        
        vector<Node> min;
        for(int i = 0;i < sz;i++)
            if(lists[i])
                min.push_back(Node(i,lists[i]));
        make_heap(min.begin(),min.end(),Compare());

        ListNode *head = NULL,*curr = NULL;
        while(!min.empty()){
            ListNode *next = min.front().node;
            int idx = min.front().idx;
            lists[idx] = next->next;
            pop_heap(min.begin(),min.end(),Compare());
            min.pop_back();
            if(lists[idx]){
                min.push_back(Node(idx,lists[idx]));
                push_heap(min.begin(),min.end(),Compare());
            }
            if(!head){
                head = next;
                curr = next;
            }
            else{
                curr->next = next;
                curr = curr->next;
            }
        }
        
        return head;
    }
};
```

设n为k个链表的节点总数：

* **时间复杂度**：O(nlogk)
* **空间复杂度**：O(n)，每个链表节点在添加到堆中都会生成一个节点

### 方法二

假设有k个链表，每次将k个链表中，每2个链表进行合并，可以得到k/2个新的链表。接着对k/2个链表中的每2个链表进行合并，又可以得到k/4个新的链表...如此反复，最终合并到只有1个链表

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz = lists.size();
        if(sz == 0) return NULL;
        if(sz == 1) return lists[0];
        
        vector<ListNode*> mergeLists;
        for(int i = 0;i < sz - 1;i += 2){
            ListNode *l1 = lists[i],*l2 = lists[i + 1];
            ListNode *mergelist = l1 && l2 ? NULL : (l1 ? l1 : l2),*curr = NULL;
            while(l1 && l2){
                ListNode *next;
                if(l1->val < l2->val){
                    next = l1;
                    l1 = l1->next;
                }else{
                    next = l2;
                    l2 = l2->next;
                }
                if(!mergelist){
                    mergelist = next;
                    curr = next;
                }
                else{
                    curr->next = next;
                    curr = curr->next;
                }
            }
            if(curr && l1)  curr->next = l1;
            else if(curr && l2)  curr->next = l2;
            mergeLists.push_back(mergelist);
        }
        
        if(sz % 2)  mergeLists.push_back(lists[sz - 1]);
        
        return mergeKLists(mergeLists);
    }
};
```

设n为k个链表的节点总数：

* **时间复杂度**：O(nlogk)
* **空间复杂度**：O(1)

<br>

[这题的方法汇总](https://leetcode.com/problems/merge-k-sorted-lists/solution/)
