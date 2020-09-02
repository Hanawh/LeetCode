class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int len = nums.size();
        vector<unsigned int> dp(target+1);
        dp[0] = 1;
        for(int i=1; i<target+1; ++i){
            for(int j=0; j<len; ++j){
                int cur = nums[j];
                if(cur <= i){
                    dp[i] += dp[i-cur];
                }
            }
        }
        return dp[target];
    }
};
