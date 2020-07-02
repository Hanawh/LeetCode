//二分法
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while(left < right){
            int mid = left + (right - left) / 2;
            int num = count(matrix, mid); //小于等于mid的个数
            if(num >= k) right = mid;
            else left = mid+1;
        }
        return left;
    }

    int count(vector<vector<int>>& matrix, int mid){
        int n = matrix.size();
        //从左下角开始走
        int i = n-1;
        int j = 0;
        int num = 0;
        //判断边界
        while(i>=0 and j<n){
            if(matrix[i][j] <= mid){ //该列都小于mid
                num += i+1;
                j++;
            }
            else i--;
        }
        return num;
    }
};

//归并排序
struct node{
    int val, x, y;
    node(int a, int b, int c) : val(a), x(b), y(c) {}
    bool operator> (const node& tmp) const{
        return this->val > tmp.val;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<node, vector<node>, greater<node> > q; //emplace原料 push加工
        int row = matrix.size();
        for(int i = 0; i < row; ++i){
            q.emplace(matrix[i][0], i, 0);
        }
        for(int i = 1; i < k; ++i){
            node cur = q.top();
            q.pop();
            if(cur.y != row-1){
                q.emplace(matrix[cur.x][cur.y+1], cur.x, cur.y+1);
            }
        }
        return q.top().val;
    }
};
