class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(k==0) return 1;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int> > q;
        vector<vector<int> > visited(m, vector<int>(n, 0));
        q.push(make_pair(0, 0));
        visited[0][0] = 1;
        int res = 1;
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int d=0; d<4; ++d){
                int row = i + dir[d][0];
                int col = j + dir[d][1];
                if(row>=0 and row<m and col>=0 and col<n and isValid(row, col, k) and visited[row][col]==0){
                    q.push(make_pair(row, col));
                    visited[row][col] = 1;
                    res++;
                }
            }
        }
        return res;
    }

    bool isValid(int num1, int num2, int range){
        int sum = 0;
        while(num1){
            sum += num1 % 10;
            num1 /= 10;
        }

        if(sum > range) return false;

        while(num2){
            sum += num2 % 10;
            num2 /= 10;
        }

        if(sum > range) return false;
        return true;
    }
};
