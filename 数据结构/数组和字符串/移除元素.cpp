/*
给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        if(size == 0) return 0;
        int cur = 0;
        for(int i = 0; i < size; ++i){
            if(nums[i] != val) nums[cur++] = nums[i]; 
        }
        return cur;
    }
};
