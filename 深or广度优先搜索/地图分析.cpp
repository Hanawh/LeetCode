class Solution {
public:
    int maxDistance(vector<vector<int> >& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int> > q;
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(grid[i][j] == 1){
                    q.push(make_pair(i,j)); //将所有陆地1入栈
                    dist[i][j] = 0;
                }
            }
        }
        if(q.empty() or q.size()==rows*cols) return -1;
        

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
            int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
            if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                    dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                    q.push(make_pair(new_r, new_c));
                }
                }
             }    
        }

        int res = 0;
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(dist[i][j]!=INT_MAX and dist[i][j]>res) res = dist[i][j];
            }
        }
        return res;
    }
};
