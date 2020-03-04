class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row  = grid.size();
        int col = grid[0].size();
        queue<pair<int, int> > q;
        int num;
        int step = -1;
        //将所有的2入队
        int one = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                } 
                else if(grid[i][j]==1)  one++;
            }
        }

        if(one==0) return 0;
        if(q.empty()) return -1;

        //扩展队列
        while(!q.empty()){
            num = q.size();
            step ++;
            for(int k = 0; k < num; ++k){
                auto temp = q.front();
                int i = temp.first;
                int j = temp.second;
                //扩展
                if(i-1>=0 and grid[i-1][j] == 1) {q.push(make_pair(i-1, j)), grid[i-1][j]=2;}
                if(i+1<row and grid[i+1][j] == 1) {q.push(make_pair(i+1, j)), grid[i+1][j]=2;}
                if(j-1>=0 and grid[i][j-1] == 1) {q.push(make_pair(i, j-1)), grid[i][j-1]=2;}
                if(j+1<col and grid[i][j+1] == 1) {q.push(make_pair(i, j+1)), grid[i][j+1]=2;}
                q.pop();
            }
        }

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j]==1){
                    return -1;
                } 
            }
        }

        return step;

    }
};
