class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto &i:nums){
            m[i]++;
        }

        vector<pair<int, int> > v;
        for(auto &i:m){
            v.push_back(i);
        }

        sort(v.begin(),v.end(),cmp);
        //前k个
        vector<int> res;
        for(int i=0; i<k; ++i){
            res.push_back(v[i].first);
        }
        return res;
    }
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second>b.second;
    }
};
