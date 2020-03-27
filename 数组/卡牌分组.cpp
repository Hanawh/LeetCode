class Solution {
    int cnt[10000];
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (auto &x: deck) m[x]++;
        int tmp=0;
        for(auto &item : m){
            if(tmp) tmp = gcd(tmp, item.second);
            else tmp = item.second;
        }
        return tmp >= 2;
    }

    int gcd(int i, int j){
        if(i%j == 0) return j;
        else{
            return gcd(j, i%j);
        }
    }
};
