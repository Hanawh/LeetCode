class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 1);  //以[i]结尾的最长子序列的长度
        vector<int> num(len, 1); //以[i]结尾的最长子序列的方法数 本身就为1种
        int maximum = 0;
        for(int i=0; i<len; ++i){
            for(int j=0; j<i; ++j){
                if(nums[i] > nums[j]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        num[i] = num[j];
                    }
                    else if(dp[j]+1 == dp[i]){
                        num[i] = num[i] + num[j];
                    }
                }
            }
            maximum = max(maximum, dp[i]);
        }
        
        int res = 0;
        for(int i=0; i<len; ++i){
            if(dp[i] == maximum) res+=num[i];
        }
        return res;
    }
};
// 1 3 5 4 7
// 1 2 3 3 4 dp
// 1 1 1 1 2 num
