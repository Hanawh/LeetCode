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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast){
            if(fast->next) fast = fast->next->next;
            else break;
            slow = slow->next;
        }
        return slow;
    }
};
