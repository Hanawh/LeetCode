/*
head = [4,5,1,9]
输入: head = [4,5,1,9], node = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
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
    void deleteNode(ListNode* node) {
        if(node == nullptr) return;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main(){
    vector<int> list{4,5,1,9};
    ListNode *head, *p;
    head = new ListNode(0);
    p = head;
    for(auto &i:list){
        ListNode *temp = new ListNode(i);
        p->next = temp;
        p = temp;
    }

    cout << "please input the node value that you want to delete:" << endl;
    int i, j = 0;
    cin >> i; //所删除节点的val
  
    p = head->next;
    while(p != NULL){
        if(p->val == i){
            Solution().deleteNode(p);
            break;
        }
        p = p->next;
    }

    p = head->next; //输出看一下
    while(p != NULL){
        cout << p->val << endl;
        p = p->next;
    }
   
    return 0;
}
