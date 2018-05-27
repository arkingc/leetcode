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