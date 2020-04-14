class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }

        ListNode* head = nullptr;
        int a, b;
        int step = 0;
        while(!s1.empty() or !s2.empty() or step != 0){
            if(!s1.empty()){
                a = s1.top();
                s1.pop();
            }
            else a = 0;

            if(!s2.empty()){
                b = s2.top();
                s2.pop();
            }
            else b = 0;

            int sum = a + b + step;
            auto cur = new ListNode(sum%10);
            step = sum/10;

            cur->next = head;
            head = cur;
        }
        return head;
    }
};
