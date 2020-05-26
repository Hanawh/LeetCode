struct TrieNode{
    string word;
    TrieNode* next[26] = {nullptr};
};

class Solution {
public:
    TrieNode *node = new TrieNode();
    vector<string> res;
    int row, col;
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        row = board.size();
        if(row == 0) return res;
        col = board[0].size();
        if(col == 0) return res;

        //建立所有单词的前缀树
        for(auto &word : words){
            TrieNode *cur = node;
            for(auto &ch : word){
                if(cur->next[ch-'a'] == nullptr) {
                    cur->next[ch-'a'] = new TrieNode();
                }
                cur = cur->next[ch-'a'];
            }
            cur->word = word;
        }

        //dfs搜索
         for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                dfs(board, node, i, j);
            }
        }
        return res;
    }

    void dfs(vector<vector<char> >& board, TrieNode* root, int i, int j){
        if(i < 0 or i >= row or j < 0 or j >= col) return;
        char ch = board[i][j];
        if(ch == '*' or root->next[ch-'a'] == nullptr) return;
        root = root->next[ch-'a'];
        board[i][j] = '*'; //已访问

        if(!root->word.empty()){
            res.push_back(root->word);
            root->word = ""; //避免重复找寻
        }

        for(int k = 0; k < 4; ++k){
            int new_row = i + dir[k][0];
            int new_col = j + dir[k][1];
            dfs(board, root, new_row, new_col);
        }
        board[i][j] = ch;
    }
};
