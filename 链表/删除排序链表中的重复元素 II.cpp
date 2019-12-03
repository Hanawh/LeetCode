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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* newList = new ListNode(-1);
        ListNode* newcur = newList;
       
        ListNode* cur = head;
        ListNode* next;
        int n = 0;
        while (cur)
        {
            next = cur->next;
            while(next && next->val == cur->val){//说明cur重复
                n++;
                next = next->next;
            }
            if(n==0){
                newcur->next = cur;
                newcur = newcur->next;
            }
            cur=next;
            n=0;
        }
        newcur->next = nullptr;
        return newList->next;
    }
};
