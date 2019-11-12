//单链表中的节点应该具有两个属性：val 和 next
#include<iostream>
using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head=NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size or index < 0) return -1;
        Node* cur = head;
        for(int i = 0; i<index; ++i){
            cur = cur->next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* cur = head;
        Node* n = new Node(val);
        while(cur and cur->next){
            cur = cur->next;
        }
        cur->next = n;
        size ++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == size) return addAtTail(val);
        if(index < 0) return addAtHead(val);
        if(index > size) return;
        Node* n = new Node(val);
        Node *cur = head;
        for (int i = 0; i < index - 1; ++i) cur = cur->next; //指向index的前一位
        n->next = cur->next;
        cur->next = n;
        size ++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 or index >= size) return;
        if (index == 0) {
            head = head->next;
            size--;
            return;
        }
        Node *cur = head;
        for (int i = 0; i < index - 1; ++i) cur = cur->next;
        cur->next = cur->next->next;
        size--;
    }
private:
    struct Node {
        int val;
        Node* next;
        Node(int x): val(x), next(nullptr) {}
    };
    Node *head;
    int size;
};

