class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> uniq(words.begin(), words.end());
        for(auto &str : uniq){
            for(int i = 1; i<str.size(); ++i){
                uniq.erase(str.substr(i));
            }
        }

        int ans = 0;
        for (const string& word: uniq) {
            ans += word.size() + 1;
        }
        return ans;      
    }
};
