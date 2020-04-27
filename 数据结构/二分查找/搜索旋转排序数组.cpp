//方法一
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

//方法二
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return -1;
        if(len == 1 and nums[0]!=target) return -1;
        int left = 0, right = len - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < nums[right]){ //[mid,right]有序-->[mid+1,right]有序
                if(target >= nums[mid+1] and target <= nums[right]){
                    left = mid + 1;//[mid+1,right]
                }
                else right = mid;//[left,mid]
            }
            else if(nums[mid] > nums[right]){//[left,mid]有序
                if(target >= nums[left] and target <= nums[mid]){ //左半边有序
                    right = mid;//[left,mid]
                }
                else left = mid + 1;//[mid+1,right]
            }
            //判断收缩行为：
            //第一种情况：int mid = (left + right + 1) >>> 1
            //第二种情况：int mid = (left + right) >>> 1
            //修改第一种情况 假定[mid+1,right]有序
        }
        if(nums[left]==target) return left;
        return -1;
    }
};//100%
