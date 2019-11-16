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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode* p = res;
        int val = 0, l1_val, l2_val;
        while (l1 != nullptr || l2 != nullptr)
        {
            if(l1 != nullptr) l1_val = l1->val;
            else l1_val = 0;

            if(l2 != nullptr) l2_val = l2->val;
            else l2_val = 0;

            val += l1_val + l2_val;
            p->next = new ListNode(val % 10);
            p = p->next;
            val /= 10;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(val){
            p->next = new ListNode(val % 10);
        }
        return res->next;
    }
};
