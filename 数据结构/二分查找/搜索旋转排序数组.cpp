class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        if(nums.size()==1) return nums[0]==target?0:-1;
        int loc=nums.size()-1;
        for(int i=0; i<nums.size()-1; ++i){
            if(nums[i+1]<nums[i]) {
                loc = i;
                break;
            }
        }
        int res = search_(nums,target,0,loc);
        if(res == -1){
            res = search_(nums,target,loc+1,nums.size()-1);
        }
        return res;
    }

    int search_(vector<int>& nums, int target, int left, int right){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){ return mid; }
            else if(nums[mid] < target) { left = mid + 1; }
            else { right = mid - 1; }
        }
        return -1;
    }
};//33
