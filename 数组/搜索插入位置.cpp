class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0) return -1;
        int left = 0;
        int right = size;
        //此时搜索范围是[0~size]
        while(left < right){ //退出时一定有left=right
            int mid = left + (right - left) / 2; //偶数的话是左中位数
            if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return right;
    }
};
