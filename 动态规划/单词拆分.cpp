class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> table(len+1); //代表第几个字符为结尾的子串是否可以分解
        unordered_set<string> word;
        for (auto w: wordDict) {
            word.insert(w);
        }
        
        table[0] = true; //
        for(int i = 0; i < len; ++i){ //遍历s
            for(int j = 0; j <= i; ++j){
                if(table[j] and word.find(s.substr(j, i-j+1))!=word.end()){
                    table[i+1] = true;
                    break;
                }
            }
        }
        return table[len];
    }
};
