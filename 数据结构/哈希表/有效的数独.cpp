class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<int,int> > row(9);
        unordered_map<int, unordered_map<int,int> > col(9);
        unordered_map<int, unordered_map<int,int> > block(9);

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    int val = board[i][j]-'0';
                    int blk = (i/3)*3+(j/3);
                    
                    row[i][val]++;
                    col[j][val]++;
                    block[blk][val]++;

                    if(row[i][val]>1 || col[j][val]>1 || block[blk][val]>1) return false;
                }
            }
        }
        return true;
    }
};//很慢 并且占内存
