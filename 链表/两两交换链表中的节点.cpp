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
    ListNode* swapPairs(ListNode* head) {
         if(head == nullptr or head->next == nullptr) return head;
        ListNode* tmp1 = head->next;
        ListNode* tmp2 = head->next->next;
        tmp1->next = head;
        ListNode* cur = swapPairs(tmp2); //返回交换后的头节点
        head->next = cur;
        return tmp1;
    }

};
