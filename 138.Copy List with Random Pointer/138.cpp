/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)   return NULL;
        
        RandomListNode *p = head;
        while(p){
            RandomListNode *nd = new RandomListNode(p->label);
            nd->next = p->next;
            p->next = nd;
            p = nd->next;
        }
        
        //这一轮循环不能拆链表，因为后面的节点的random可能指向前面的节点，
        //如果在设置random成员的同时拆链表，由于前面的节点已经拆开，所以新链表
        //节点的random成员会指向旧链表的节点
        p = head;
        while(p){
            if(p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        
        p = head;
        head = p->next; //更新head指向复制出的新链表的表头
        while(p){
            RandomListNode *tp = p->next;
            p->next = tp->next;
            p = p->next;
            if(p)
                tp->next = p->next;
        }
        
        return head;
    }
};