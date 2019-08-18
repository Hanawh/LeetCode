/*
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        bool meet = false;

        while (slow != nullptr && fast != nullptr){ //找到快慢指针相遇的节点
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr) fast = fast->next;

            if(slow != nullptr && fast != nullptr && slow == fast){ 
                meet = true; 
                break; 
            }
        }
        return meet;
    }
};

int main(){
    vector<int> list{1, 2};
    int pos = 0;
    ListNode *head, *p, *cur;
    head = new ListNode(-1);
    p = head;
    for(auto &i:list){
        ListNode *temp = new ListNode(i);
        p->next = temp;
        p = temp; //p指向末节点
    }
    ListNode *res = head->next;
    free(head);

    cur = res; //找出第pos个节点
    int i=0;
    if(pos >= 0){
        while (i <= pos)
        {
            if(i == pos){
                p->next = cur;
                break;
            }
            ++i;
            cur = cur->next;
        }
    }

    cout << boolalpha << Solution().hasCycle(res) << endl;
    return 0;
}
