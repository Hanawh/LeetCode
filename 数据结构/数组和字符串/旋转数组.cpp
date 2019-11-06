/*
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int len = nums.size();
        if(k > len) k = k % len;
        reverse(nums.begin(),nums.end());
        reverse(&nums[0],&nums[k]);
        reverse(nums.begin() + k, nums.end());
    }
};
