/*
输入:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: true
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int number,k;
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool blocks[9][9] = {false};
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(board[i][j] == '.') continue;
                number = board[i][j]-'1';
                k = i/3*3+j/3;                          //转变为框的索引
                if(rows[i][number] or cols[j][number] or blocks[k][number]) return false;
                rows[i][number]=cols[j][number]=blocks[k][number]=true;
            }
        }
        return true;
    }
};
int main()
{
   vector<vector<char>>  A = {
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}
	};
    bool result=Solution().isValidSudoku(A);
    cout<<boolalpha<<result<<endl;
    return 0;
}
