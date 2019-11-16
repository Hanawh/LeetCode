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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //用新的节点去存储新链
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while(cur1 && cur2){
            if (cur1->val <= cur2->val){
                cur->next = cur1;
                cur1 = cur1->next;
            }
            else{
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        if(cur1) cur->next = cur1;
        else if(cur2) cur->next = cur2;
        return res->next;
    }
};
