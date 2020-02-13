class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> m;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.count(val)) return false;
        m[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!m.count(val)) return false;
        int size = v.size();
        int loc = m[val];

        v[loc] = v[size-1];
        m[v[size-1]] = loc;
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int size=v.size();
        if(size == 0) return 0;
        int index=rand()%size;
        return v[index];
    }
};
