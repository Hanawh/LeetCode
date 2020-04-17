class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        //sort(intervals.begin(), intervals.end(), cmp);
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > res;
        for(int i = 0; i < intervals.size(); ++i){
            int left = intervals[i][0];
            int right = intervals[i][1];
            if(!res.size() or res.back()[1] < left){
                res.push_back({left, right});
            }
            else{
                res.back()[1] = max(res.back()[1], right);
            }
        }
        return res;
    }
    /*
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    */
};
