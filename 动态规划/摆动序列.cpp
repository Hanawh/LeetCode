//面对测试用例编程- - O(n^2)
struct dpnode{
    int len; //代表以当前位置结尾 最长子序列的长度
    int preind; //代表以当前位置结尾 最长子序列的前驱序号
};
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;
        vector<dpnode> dp(len);
        int res = 1;
        for(int i=0; i<len; ++i){
            dp[i].len = 1;
            dp[i].preind = -1;
            for(int j=0; j<i; ++j){
                int ind = dp[j].preind;
                if(ind!=-1 and (nums[i]-nums[j]) * (nums[j]-nums[ind]) < 0){
                    dp[i].len = max(dp[i].len, dp[j].len + 1);
                    dp[i].preind = j;
                }
                if(ind == -1 and nums[j] != nums[i]){
                    dp[i].len = max(dp[i].len, dp[j].len + 1);
                    dp[i].preind = j;
                }
            }
            res = max(res, dp[i].len);
        }
        return res;
    }
};

//转换思路 ：求波峰+波谷的数量，只需要在相邻点发生差值变化的时候，结果集加1即可
