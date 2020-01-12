class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = nums.size();
        vector<vector<int> > sum(len, vector<int>(2));
        for(int i = 0; i < len; ++i){
            // 每个房子的状态: 0不偷 1偷
            if(i == 0){
                sum[i][0] = 0;
                sum[i][1] = nums[i];
            }
            else if(i == 1){
                sum[i][0] = max(sum[i-1][0],sum[i-1][1]);
                sum[i][1] = nums[i];
            }
            else{
                sum[i][0] = max(sum[i-1][0],sum[i-1][1]);
                sum[i][1] = max(sum[i-2][0],sum[i-2][1]) + nums[i]; 
            }
        }
        return max(sum[len-1][0],sum[len-1][1]);
    }
};
