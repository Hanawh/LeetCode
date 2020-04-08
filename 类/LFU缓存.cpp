struct Node{
    int key, val, freq;
    Node(int _key, int _val, int _freq):key(_key), val(_val), freq(_freq){}
};

class LFUCache {
    int minFreq, capacity;
    unordered_map<int, list<Node>::iterator> keymap;
    unordered_map<int, list<Node> > freqmap;
public:
    LFUCache(int _capacity) {
        minFreq = 0;
        capacity = _capacity;
        keymap.clear();
        freqmap.clear();
    }

    int get(int key) {
        // 先根据key在keymap找到位置
        if(capacity == 0) return -1;
        auto it = keymap.find(key);
        if(it == keymap.end()) return -1;
        list<Node>::iterator node = it->second;
        int val = node->val;
        int freq = node->freq;
        //更新node的freq 先在freqmap删除
        freqmap[freq].erase(node);
        //有删除就得判断是否为空
        if(freqmap[freq].size() == 0){
            freqmap.erase(freq);
            if (minFreq == freq) minFreq += 1;
        }
        freqmap[freq+1].push_front(Node(key, val, freq+1)); //从前端插入保证最近访问
        keymap[key] =  freqmap[freq+1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        auto it = keymap.find(key);
        if(it == keymap.end()){
            //没有键值先判断capacity再插入
            if(keymap.size() == capacity){
                //删除最小访问频率minFreq链表最末端
                auto it2 = freqmap[minFreq].back();
                freqmap[minFreq].pop_back();
                keymap.erase(it2.key);
            }
            //插入
            freqmap[1].push_front(Node(key, value, 1));
            keymap[key] = freqmap[1].begin();
            minFreq = 1;
        }
        else{
            //有键值就更新
            list<Node>::iterator node= it->second;
            int freq = node->freq;
            freqmap[freq].erase(node);
            if(freqmap[freq].size() == 0){
                freqmap.erase(freq);
                if(minFreq == freq) minFreq += 1;
            }
            freqmap[freq+1].push_front(Node(key, value, freq+1)); //从前端插入保证最近访问
            keymap[key] =  freqmap[freq+1].begin();
        }
    }
};
