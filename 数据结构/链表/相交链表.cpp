/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        //统计各链表的长度
        ListNode* a=headA;
        ListNode* b=headB;
        int len1 = 0;
        int len2 = 0;
        while(a != nullptr){
            len1 ++;
            a = a->next;
        }
        
        while(b != nullptr){
            len2 ++;
            b = b->next;
        }
        int k;
        //比较长短,将长的赋予a
        if(len1 < len2){
            k = len2-len1;
            a = headB;
            b = headA;
        }
        else{
            k = len1-len2;
            a = headA;
            b = headB;
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
