struct TrieNode{
    int index = -1; //该单词的索引号
    TrieNode* next[26] = {nullptr};
    vector<int> prefix; //该字符之后是否是回文
};

class Solution {
public:
    TrieNode *node = new TrieNode();
    vector<vector<int> > palindromePairs(vector<string>& words) {
        //将每个words倒序
        vector<string> reverse;
        for(auto & word : words){
            string str(word.rbegin(), word.rend());
            reverse.push_back(str);
        }

        //将reverse后的单词建立Trie
        for(int i = 0; i < reverse.size(); ++i){
            TrieNode *cur = node;
            if(isPalindrome(reverse[i])) cur->prefix.push_back(i);
            for(int j = 0; j < reverse[i].size(); ++j){
                char ch = reverse[i][j];
                if(cur->next[ch-'a'] == nullptr) {
                    cur->next[ch-'a'] = new TrieNode();
                }
                cur = cur->next[ch-'a'];
                if(isPalindrome(reverse[i].substr(j+1))) cur->prefix.push_back(i);
            }
            cur->index = i;
        }


        //已知当前字符串s1,查找前缀s2,分三种情况
        vector<vector<int> > res;
        for(int i = 0; i < words.size(); ++i){
            TrieNode *cur = node;
            string word = words[i];
            bool longer = true; //默认s1 <= s2

            for(int j = 0; j < word.size(); ++j){
                //s1 > s2 判断s2剩下的是回文
                if (isPalindrome(word.substr(j)) and cur->index != -1){
                    res.push_back({i, cur->index});
                }
                if(cur->next[word[j]-'a'] == nullptr) {
                    longer = false;
                    break;
                }
                cur = cur->next[word[j]-'a'];
            }
            //s1 < s2 判断s1剩下的是回文
            if(longer) {
                for(auto k : cur->prefix){
                    if(k != i) res.push_back({i, k});
                }
            }
        }
        return res;
    }

    bool isPalindrome(string s){
        int i = 0, j = s.size()-1;
        while (i < j){
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
