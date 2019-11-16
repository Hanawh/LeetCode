/*
输入: 1->2
输出: false
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* temp;
        ListNode* pre;
        //奇数：slow在中间 fast为最后一位数
        //偶数：slow在后半段首 fast为null
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //将后半段倒置
        fast = slow->next;
        slow->next = nullptr;
        
        pre = nullptr;
        while(fast){
            temp = fast->next;
            fast->next = pre;
            pre = fast;
            fast = temp;
        }
        
        //同时比较
        while(head && pre){
            if(head->val != pre->val){
                return false;
            }
            head = head->next;
            pre = pre->next;
        }
        return true;
        
    }
};
