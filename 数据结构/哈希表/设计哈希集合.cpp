struct Node{
    int val;
    Node* next;
    Node(int val):val(val),next(nullptr){}
};

const int len = 100;

class MyHashSet {
public:
    vector<Node*> arr;
    /** Initialize your data structure here. */
    MyHashSet() {
       arr = vector<Node*>(len, new Node(-1));
    }
    
    void add(int key) {
        int t = key % len;
        Node* tmp = arr[t];
        if(tmp->val == -1) tmp->val = key;
        else{
            while(tmp->next){
                //去重
                if(tmp->val == key) return;
                tmp = tmp->next;
            }
            if(tmp->val == key) return;
            Node* insert = new Node(key);
            tmp->next = insert;
        }
    }
    
    void remove(int key) {
        int t = key % len;
        Node* tmp = arr[t];
        if(tmp->val != -1){
            while(tmp){
                if(tmp->val == key){
                    tmp->val = -1;
                    return;
                }
                tmp = tmp->next;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int t = key % len;
        Node* tmp = arr[t];
        while(tmp){
            if(tmp->val == key) return true;
            tmp = tmp->next;
        }
        return false;
    }
};
