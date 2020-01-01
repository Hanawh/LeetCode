class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return false;
        int sum = 0;
        for(int i = 0; i < len; ++i){
            sum += nums[i];
        }
        if(sum % 2) return false;

        int target = sum / 2;
        vector<vector<bool> > table(len, vector<bool>(target+1, false));
        table[0][nums[0]] = true;
        for(int i = 1; i < len; ++i){
            for(int j = 0; j < target+1; ++j){
                table[i][j] = table[i-1][j];
                if(nums[i] < j){
                    table[i][j] = table[i-1][j] or table[i-1][j-nums[i]];
                }
                else if(nums[i] == j){
                    table[i][j] = true;
                }
            }
        }
        return table[len-1][target];
    }
};
