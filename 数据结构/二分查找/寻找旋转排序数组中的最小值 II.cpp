class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int i=0, j=len-1;
        if(nums[len-1]>nums[0]) return nums[0];
        while(i<=j){ //[i,j]
            int mid = i+(j-i)/2;
            if(nums[mid]>nums[j]) i=mid+1; //[mid+1,j]
            else if(nums[mid]<nums[j]) j=mid; //[i,mid]
            else  j--;
        }
        return nums[j+1];
        /*
        while(i+1<j){ //模版三
            int mid = i+(j-i)/2;
            if(nums[mid]>nums[j]) i=mid; 
            else if(nums[mid]<nums[j]) j=mid;
            else  j--;
        }
        return nums[j];
        */
    }
};
