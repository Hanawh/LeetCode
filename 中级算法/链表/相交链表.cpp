/*
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
*/
#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};
//计算两个链表的长度差值k 先让长的链表走k步
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* a = headA;
        ListNode* b = headB;
        int lenA = 0, lenB = 0;
        //计算长度
        while(a != nullptr){
            lenA ++;
            a = a->next;
        }

        while(b != nullptr){
            lenB ++;
            b = b->next;
        }

        int k = lenA - lenB;
        if(k >= 0){
            a = headA;
            b = headB;
        }
        else{
            k *= -1;
            a = headB;
            b = headA;
        }

        while(k--){
            a = a->next;
        }

        while(a != b){
            a = a->next;
            b = b->next;
        }
        return a;
    }
};

