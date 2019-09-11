/*
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
*/
#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp = even;
        while(even && even->next){ //1->2 1->3->5->2->4
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = temp;
        return head;
    }
};

int main(){
    vector<int> listA{1, 3, 5, 2, 4};
    ListNode *headA, *pA;
    headA = new ListNode(-1);
    pA = headA;
    for(auto &i:listA){
        ListNode *temp = new ListNode(i);
        pA->next = temp;
        pA = temp;
    }
    pA = headA;
    headA = headA->next;
    free(pA);
    
    ListNode *t = Solution().oddEvenList(headA);
    while(t != NULL){
        cout << t->val << endl;
        t = t->next;
    }
    
    return 0;
}
