class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > m;
        vector<vector<string> > res;
        for(auto &s : strs){
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        for(auto &item : m){
            res.push_back(item.second);
        }
        return res;
    }
};
