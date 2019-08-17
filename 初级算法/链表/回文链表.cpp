/*
输入: 1->2->2->1
输出: true
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode *first = head;
        ListNode *sec = head->next;

        while (sec != nullptr && sec->next !=nullptr){
            sec = sec->next->next;   //2->1->null (sec = nullptr)
            first = first->next;     //1->2->1 (first = last 1)
        }
    
        ListNode *cur = first->next; //记录sec的头指针
        first->next = nullptr; //分为first和sec两个子链
        ListNode *pre = nullptr; //将sec倒置
        ListNode *temp;
        while (cur != nullptr){
            temp = cur;
            cur = cur->next;
            temp->next = pre;
            pre = temp;
        }
        
        //判断
        while (head != nullptr && pre != nullptr){
            if (pre->val != head->val) return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};

int main(){
    vector<int> list{1, 2, 1, 2, 1};
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

    cout << boolalpha << Solution().isPalindrome(res) << endl;
    return 0;
}
