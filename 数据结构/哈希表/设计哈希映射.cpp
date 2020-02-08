struct Node{
    int key;
    int val;
    Node* next;
    Node(int key, int val):key(key),val(val),next(nullptr){}
};

const int len = 100;

class MyHashMap {
public:
    vector<Node*> arr;
    /** Initialize your data structure here. */
    MyHashMap() {
       arr = vector<Node*>(len, new Node(-1,-1));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int t = key % len;
        Node* tmp = arr[t];
        if(tmp->val == -1){
            tmp->val = value;
            tmp->key = key;
        }
        else{
            while(tmp->next){
                //去重
                if(tmp->key == key){
                    tmp->val=value;
                    return;
                }
                tmp = tmp->next;
            }
            if(tmp->key == key){
                tmp->val=value;
                return;
            }
            Node* insert = new Node(key,value);
            tmp->next = insert;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int t = key % len;
        Node* tmp = arr[t];
        while(tmp){
            if(tmp->key==key){
                return tmp->val;
            }
            tmp = tmp->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int t = key % len;
        Node* tmp = arr[t];
        while(tmp){
            if(tmp->key == key){
                tmp->val = -1;
                return;
            }
            tmp = tmp->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
