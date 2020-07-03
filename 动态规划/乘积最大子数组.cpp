class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        vector<vector<int> > tb(len, vector<int>(2)); //记录以当前数组为结尾的最大乘积和最小乘积
        int res = nums[0];
        tb[0][0] = nums[0];
        tb[0][1] = nums[0];
        for(int i = 1; i < len; ++i){
            if(nums[i] > 0){
                tb[i][0] = max(nums[i], tb[i-1][0]*nums[i]);
                tb[i][1] = min(nums[i], tb[i-1][1]*nums[i]);
            }
            else{
                tb[i][0] = max(nums[i], tb[i-1][1]*nums[i]);
                tb[i][1] = min(nums[i], tb[i-1][0]*nums[i]);
            }
            res = max(res, tb[i][0]);
        }
        return res;
    }
};
