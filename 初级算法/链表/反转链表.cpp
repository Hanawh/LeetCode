/*
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        ListNode *temp;
        while (cur != nullptr)
        {
            temp = cur->next;//先保存下一个节点
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main(){
    vector<int> list{4,5,1,9};
    ListNode *head, *p;
    head = new ListNode(-1);
    p = head;
    for(auto &i:list){
        ListNode *temp = new ListNode(i);
        p->next = temp;
        p = temp;
    }

    p = Solution().reverseList(head->next);
    while(p != NULL){
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
