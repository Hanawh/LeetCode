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
        Node* n = new Node(val,head);
        head = n;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* cur = head;
        Node* n = new Node(val,NULL);
        while(cur->next){
            cur = cur->next;
        }
        cur->next = n;
        size ++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
       if (index < 0 || index > size) return;
        if (index == 0) {addAtHead(val); return;}
        Node *cur = head;
        for (int i = 0; i < index - 1; ++i) cur = cur->next;
        Node *t = new Node(val, cur->next);
        cur->next = t;
        size++;
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
        Node(int x, Node* n): val(x), next(n) {}
    };
    Node *head;
    int size;
};
