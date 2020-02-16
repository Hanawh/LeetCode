class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int i=0, j=len-1;
        if(nums[j]>nums[i]) return nums[0];
        while(i<j){
            int mid = i+(j-i)/2;
            if(nums[mid]>nums[mid+1]) return nums[mid+1];
            if(nums[mid]<nums[mid-1]) return nums[mid];//[3,1,2]
            if(nums[mid]>nums[len-1]) i=mid+1;
            else j=mid;
            
        }
        return nums[i];
    }
};//153
