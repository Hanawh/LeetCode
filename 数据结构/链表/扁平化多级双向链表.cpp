/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head==nullptr)
            return nullptr;
        Node*cur=head;
        
        while(cur!=nullptr)
        {
            if(cur->child!=nullptr)
            {
                auto child=cur->child;
                auto curNext=cur->next;
                child->prev=cur;
                cur->next=child;
                cur->child=nullptr;
                while(child->next!=nullptr)
                    child=child->next;
                if(curNext!=nullptr)
                {
                    curNext->prev=child;
                    child->next=curNext;
                }
                
            }
            cur=cur->next;
 
        }
         return head;
    }
};
