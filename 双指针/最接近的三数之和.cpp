class Solution {
public:
    int maxval = INT32_MAX;
    int res;
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 2; ++i){
            int left = i + 1;
            int right = len - 1;
            while(left < right){
                int sum = nums[i] + nums[right] + nums[left];
                int temp = abs(sum - target);
                if(temp < maxval) {
                    maxval = temp;
                    res = sum;
                }
                if(sum > target) right--;
                else left++;
            }
        }
        return res;
    }
};
