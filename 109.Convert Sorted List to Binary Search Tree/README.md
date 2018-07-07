## 题目

给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

```
给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
 ```

## 解答

首先变量链表统计节点总数n

假设二叉搜索树的构造函数为f(n)，即构造n个节点的二叉搜索树。为了平衡，左右子树的节点应该对半分。假设为左子树分配n/2个节点，由于根节点占用了1个节点，那么需要为右子树分配n-n/2-1个节点。因此有：

```
root->left = f(n/2);
root->right = f(n-n/2-1);
```

那么root->val应该等于什么？注意上面的赋值顺序，这显然是一个递归调用的过程，在最深层会构造整棵二叉搜索树的最左子树（即最左子节点）。由于BST的性质，这个节点显然是最小值，因此应该使用链表头节点。所以左边最深处使用到第一个链表节点，那么遍历顺序就应该是中序遍历，因此root->val的设置应该在上面2个语句之间。同时，构造完一个节点后，链表也要前进一个节点：

```c++
//在对root->val赋值之前，需要为left成员赋值，因此初始化val为0
TreeNode *root = new TreeNode(0);
root->left = f(n/2);
root->val = curr->val //curr为当前链表节点
curr = curr->next;
root->right = f(n-n/2-1);
```

整个程序的代码如下：

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        int count = 0;
        while(p) {
            count++;
            p = p->next;
        }
        
        return sortedListToBSTCore(count,&head);
    }
private:
    TreeNode* sortedListToBSTCore(int count,ListNode** curr){
        if(count <= 0)  return NULL;
        
        TreeNode *root = new TreeNode(0);
        root->left = sortedListToBSTCore(count / 2,curr);
        root->val = (*curr)->val;
        (*curr) = (*curr)->next;
        root->right = sortedListToBSTCore(count - count / 2 - 1,curr);
        
        return root;
    }
};
```