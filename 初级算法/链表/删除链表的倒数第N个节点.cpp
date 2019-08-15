/*
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.
*/
#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution{
public: 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        while(n-- != 0)
            p = p->next;
         if(!p) //若删除的是首节点 
            return head->next;
         ListNode *q = head;
         while(p->next != NULL){
            p = p->next;
            q = q->next;
         }
         q->next = q->next->next;
         return head;
    }
};

int main(){
    vector<int> list{1, 2, 3, 4, 5};
    ListNode *head, *p;
    head = new ListNode(-1);
    p = head;
    for(auto &i:list){
        ListNode *temp = new ListNode(i);
        p->next = temp;
        p = temp;
    }
    ListNode *res = head->next;
    free(head);
 
    int n=2;
    Solution().removeNthFromEnd(res, n);

    p = res;
    while(p != NULL){
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
