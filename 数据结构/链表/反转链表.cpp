/*
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
*/


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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* next;
        while(cur){
            next = cur->next;
            
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(head == nullptr or head->next == nullptr) return head;
        ListNode* tmp = reverseList(head->next); //返回以逆序的头指针
        head->next->next = head;
        head->next = nullptr;
        return tmp;
    }
};
