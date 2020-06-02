class Solution {
public:
    unordered_map<string, int> mp;
    int numTrees(int n) {
        return count(1, n);
    }

    int count(int start, int end){
        if(start >= end) return 1;
        string key = to_string(start)+"to"+to_string(end);
        if(mp.find(key) != mp.end()) return mp[key];
        int sum = 0;
        for(int i = start; i <= end; ++i){
            int left = count(start, i - 1);
            int right = count(i + 1, end);
            sum += left * right;
        }
        mp[key] = sum;
        return sum;
    }
};
