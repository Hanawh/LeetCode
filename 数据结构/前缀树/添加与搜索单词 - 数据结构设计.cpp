class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        isEnd = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *cur = this;
        for(auto &ch : word){
            if(cur->next[ch-'a'] == nullptr) {
                cur->next[ch-'a'] = new WordDictionary();
            }
            cur = cur->next[ch-'a'];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(this, word);
    }

    bool dfs(WordDictionary *node, string word){
        WordDictionary *cur = node;
        bool res = false;
        for(int i = 0; i < word.size(); ++i){
            if(word[i] == '.'){
                for(int j = 0; j < 26; ++j){
                    if(cur->next[j]!=nullptr){
                        res = dfs(cur->next[j], word.substr(i+1)) or res;
                    }
                }
                return res;
            }
            else{
                if(cur->next[word[i]-'a'] == nullptr) return false;
                cur = cur->next[word[i]-'a'];
            }
        }
        if(cur->isEnd) return true;
        return res;
    }
private:
    bool isEnd;
    WordDictionary *next[26] = {nullptr};
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
