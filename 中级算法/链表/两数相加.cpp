/*
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { //前提两联表非空
        ListNode* newHead = new ListNode(0);
        ListNode* p = newHead;
        int val = 0, l1_val, l2_val;
        while (l1 != nullptr || l2 != nullptr)
        {
            if(l1 != nullptr) l1_val = l1->val;
            else l1_val = 0;

            if(l2 != nullptr) l2_val = l2->val;
            else l2_val = 0;

            val += l1_val + l2_val;
            p->next = new ListNode(val % 10);
            p = p->next;
            val /= 10;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(val){
            p->next = new ListNode(val % 10);
        }
        return newHead->next;
    }
};

int main(){
    vector<int> listA{1, 8};
    vector<int> listB{0};
    ListNode *headA, *headB, *pA, *pB;
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

    headB = new ListNode(-1);
    pB = headB;
    for(auto &i:listB){
        ListNode *temp = new ListNode(i);
        pB->next = temp;
        pB = temp;
    }
    pB = headB;
    headB = headB->next;
    free(pB);

    ListNode *t = Solution().addTwoNumbers(headA, headB);
    while(t != NULL){
        cout << t->val << endl;
        t = t->next;
    }
    
    return 0;
}
