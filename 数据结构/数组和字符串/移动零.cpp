class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int cur = 0;
        for(int i = 0; i < size; ++i){
            if(nums[i] != 0) nums[cur++] = nums[i];
        }
        for(int i = cur; i < size; ++i){
            nums[i] = 0;
        }
    }
};
