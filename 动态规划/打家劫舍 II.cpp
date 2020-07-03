class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        int res_a = robbery(nums, 0, len-2);
        int res_b = robbery(nums, 1, len-1);
        return max(res_a, res_b);
    }

    int robbery(vector<int>& nums, int left, int right){
        int rob = nums[left];
        int unrob = 0;
        for(int i=left+1; i<=right; ++i){
            //偷
            int temp = rob;
            rob = unrob + nums[i];
            //不偷
            unrob = max(temp, unrob);
        }
        return max(rob, unrob);
    }
};
