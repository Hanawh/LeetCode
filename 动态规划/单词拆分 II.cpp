class Solution {
public:
    vector<string> res;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        unordered_set<string> word;
        vector<bool> table(len+1); //代表第几个字符为结尾的子串是否可以分解
        for (auto w: wordDict) {
            word.insert(w);
        }
        
        table[0] = true; 
        for(int i = 0; i < len; ++i){ //遍历s
            for(int j = 0; j <= i; ++j){
                if(table[j] and word.find(s.substr(j, i-j+1))!=word.end()){
                    table[i+1] = true;
                    break;
                }
            }
        }
        
        if(table[len]){
            deque<string> path; //父节点到子节点的路径
            dfs(s, len, path, word, table);
        }
        return res;
    };

    void dfs(string s, int right, deque<string> path, unordered_set<string>& word, vector<bool>& dp){
        if(right == 0) {
            string tmp;
            for(int i=0; i<path.size(); ++i){
                tmp = tmp + path[i];
                if(i!=path.size()-1) tmp += ' ';
            }
            res.push_back(tmp);
        }
        for(int i=right-1; i>=0; i--){ //from right to left
            int len = right - i;
            string sub_s = s.substr(i, len);
            if(word.find(sub_s)!=word.end() && dp[i]){
                path.push_front(sub_s);
                dfs(s, i, path, word, dp);
                path.pop_front();
            }
        }
    };
};
