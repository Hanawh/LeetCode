/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head){
        if(head == nullptr) return nullptr;
        Node* cur = head;
        while(cur){
            Node* newNode = new Node(cur->val, cur->next, nullptr);
            cur->next = newNode;
            cur = cur->next->next;
        }
        
        cur = head;
        while(cur){
            if(cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        
        cur = head;
        Node* cphead = head->next;
        while(cur){
            Node* cpNode = cur->next;
            cur->next = cpNode->next;
            if(cpNode->next) cpNode->next = cur->next->next;
            cur = cur->next; 
        }
        return cphead;
    }
};
