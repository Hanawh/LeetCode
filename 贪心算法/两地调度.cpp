class Solution {
public:
    int twoCitySchedCost(vector<vector<int> >& costs) { //假设所有的先去B地 
        for(int i = 0; i < costs.size(); ++i){
            costs[i].push_back(costs[i][0]-costs[i][1]); //cost_A - cost_B差值越大 越应该留在B地
        }
        sort(costs.begin(),costs.end(),cmp);
        int sum = 0;
        for(int i = 0; i < costs.size()/2; ++i){
            sum += costs[i][0] + costs[i+costs.size()/2][1];
        }
        return sum;
    }

    static bool cmp(vector<int> a, vector<int> b){ //必须是静态函数
        return a[2] < b[2];
    }
};//12ms 11.9MB
