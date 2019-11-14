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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre=nullptr;
        ListNode* cur=head;
        ListNode* next;
        while(cur){
            if(cur->val == val){
                next = cur->next;
                if(pre == nullptr){
                    head = next;
                }
                else{
                    pre->next = next;
                }
                cur = next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return head;    
    }
};
