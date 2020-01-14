class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> res(len);
        res[0] = cost[0];
        res[1] = cost[1];
        for(int i = 2; i < len; ++i){
            res[i] = min(res[i-1],res[i-2])+cost[i];
        }
        return min(res[len-1],res[len-2]);
    }
};//8ms 8.8M

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        int pre = cost[0];
        int cur = cost[1];
        for(int i = 2; i < len; ++i){
            int temp = min(cur,pre)+cost[i]; 
            pre = cur;
            cur = temp;
        }
        return min(cur,pre);
    }
};//4ms 8.9M
