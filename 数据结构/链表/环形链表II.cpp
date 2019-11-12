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
    ListNode *detectCycle(ListNode *head) {
        //是否存在环
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;
        while (slow && fast && fast->next) {
            slow = slow->next;          
            fast = fast->next->next;  
            if (slow == fast) {         
                 flag = true;
                 break;
            }
        }
        if(flag == false) return nullptr;
        //统计环中节点个数
        fast = fast->next;
        int n=1;
        while(fast != slow){
            n++;
            fast = fast->next;
        }
        //找到环的入口节点
        slow = head;
        fast = head;
        for(int i=0; i<n; ++i){
            //fast移动n步
            fast = fast->next;
        }
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
