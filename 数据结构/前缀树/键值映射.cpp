class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        isEnd = false;
        val = 0;
    }
    
    void insert(string key, int val) {
        MapSum* node = this;
        for(auto &c:key){
            if(node->next[c-'a'] == nullptr) {
                node->next[c-'a'] = new MapSum();
            }
            node = node->next[c-'a'];
        }
        node->val = val;
        node->isEnd = true;
    }

    int sum(string s) {
        MapSum *node = this;
        int res = 0;
        for(auto &c:s){
            if(node->next[c-'a'] == nullptr) return res;
            node = node->next[c-'a'];
        }
        //需要dfs 找到所有键值
        res += dfs(node);
        return res;
    }

    int dfs(MapSum *node){
        int res = 0;
        if(node->isEnd) res += node->val;
        for(int i=0; i<26; ++i){
            if(node->next[i]){
                res += dfs(node->next[i]);
            }
        }
        return res;
    }
    
private:
    bool isEnd;
    MapSum *next[26] = {nullptr};
    int val;
};
