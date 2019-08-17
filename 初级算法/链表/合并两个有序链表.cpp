/*
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode *h = new ListNode(-1);
        ListNode *cur = h;
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        while (cur1 != nullptr && cur2 != nullptr){
            if (cur1->val <= cur2->val){
                cur->next = cur1;
                cur1 = cur1->next;
            }
            else{
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        if (cur1 != nullptr) cur->next = cur1;
        if (cur2 != nullptr) cur->next = cur2;
        ListNode* resNode = h->next;
        delete h;
        return resNode;
    }
};

int main(){
    vector<int> listA{1, 2, 4};
    vector<int> listB{1, 3, 4};
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

    ListNode *t = Solution().mergeTwoLists(headA, headB);
    while(t != NULL){
        cout << t->val << endl;
        t = t->next;
    }
    
    return 0;
}
