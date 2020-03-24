class Solution {
public:
    int massage(vector<int>& nums) {
        int len = nums.size();
        if(len==0) return 0;
        if(len==1) return nums[0];
        vector<vector<int> > res(len, vector<int>(2));
        res[0][1] = nums[0];
        res[1][0] = nums[0];
        res[1][1] = nums[1];
        for(int i=2; i<len; ++i){
            //不预约
            res[i][0] = max(res[i-1][0], res[i-1][1]);
            //预约
            res[i][1] = max(res[i-2][0], res[i-2][1]) + nums[i];
            //res[i][i] = res[i-1][0] + nums[i];
        }
        return max(res[len-1][0], res[len-1][1]);
    }
};
