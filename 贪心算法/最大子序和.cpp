class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int sum, max;
        for(int i = 0; i<nums.size(); ++i){
            if(i == 0){
                sum = nums[i];
                max = nums[i];
            }
            else{
                if(sum > 0) sum += nums[i];
                else{
                    sum = nums[i]; 
                }
                if(sum > max) max = sum;
            }
        }
        return max;
    }
};
