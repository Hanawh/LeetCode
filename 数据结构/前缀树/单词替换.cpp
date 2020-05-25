struct TrieNode {
    string s;
    TrieNode *next[26] = {nullptr};
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
         istringstream line(sentence);
        string word;
        string res="";
        TrieNode *root = new TrieNode();
        //词根 前缀树
        for(auto &prefix : dict){
            TrieNode *cur = root;
            for(auto &ch : prefix){
                if(cur->next[ch-'a'] == nullptr){
                    cur->next[ch-'a'] = new TrieNode();
                }
                cur = cur->next[ch-'a'];
            }
            cur->s = prefix;
        }
        //对于每个词替换
        while(line >> word){
            TrieNode *cur = root;
            for(auto &ch : word){
                if(cur->next[ch-'a'] == nullptr or !cur->s.empty()) break; //!cur->s.empty()为了避免相同前缀 
                cur = cur->next[ch-'a'];
            }
            res += (cur->s.empty()? word : cur->s);
            res += " ";
        }
        //删除最后一个空格 通过resize将原来数据多余的截掉
        if(res.size()>0) res.resize(res.size()-1);
        return res;
    }
};
