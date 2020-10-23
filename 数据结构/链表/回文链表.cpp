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

//method 2
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
        //寻找中点
        //反转链表
        //逐个遍历
        if(head == nullptr or head->next == nullptr) return true;
        ListNode* mid = findmid(head);
        ListNode* temp = mid->next;
        mid->next = nullptr;
        temp = invert(temp);
        return isSame(head, temp);
    }

    ListNode* findmid(ListNode* head){
        // 偶数 1234 返回2
        // 奇数 123 返回2
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr and fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* invert(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur!=nullptr){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    bool isSame(ListNode* head1, ListNode* head2){ //head1 >= head2
        while(head1 != nullptr and head2 != nullptr){
            if(head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};
