class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums){
        int len = nums.size();
        if(len == 0) return nums;
        sort(nums.begin(), nums.end()); 
        vector<int> dp(len, 1); //代表已当前数字结尾的最大整除子集的长度
        int ind = 0;
        int maxL = 0;
        for(int i=0; i<len; ++i){
            for(int j=0; j<i; ++j){
                if(nums[i] % nums[j] == 0){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            if(dp[i] > maxL){
                maxL = dp[i];
                ind = i;
            }
        }
        
        vector<int> res;
        for(int cur=ind; cur>=0; cur--){
            if(dp[cur] == maxL and nums[ind] % nums[cur] == 0){
                res.push_back(nums[cur]);
                maxL--;
                ind = cur;
            }
        }
        return res;
    }
};
