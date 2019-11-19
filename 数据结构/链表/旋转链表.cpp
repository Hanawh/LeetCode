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
    ListNode* rotateRight(ListNode* head, int k) {
         if(head == nullptr) return head;
        //遍历整个链表
        ListNode* cur = head;
        ListNode* pre = nullptr;
        int len=0;
        while(cur){
            len++;
            pre = cur;
            cur = cur->next;
        } //此时pre正好指向最后一个指针

        pre->next = head; //接连成环

        int m = len-k%len;

        while(m--){
            pre = pre->next;
        }

        ListNode *newhead = pre->next;
        pre->next = nullptr;
        return newhead;
    }
};
