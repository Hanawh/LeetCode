class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int i=0, j=len-1;
        while(i<j){
            int mid = i+(j-i)/2;
            if(nums[mid]>nums[mid+1]) j = mid;
            //大的一侧必定有峰值
            //如果nums[mid-1]<num[mid] 那么峰值就是num[mid]
            //如果nums[mid-1]>num[mid] 那么峰值就又在nums[mid-1]左边 因为最左边是负无穷 所以必有极值
            else i = mid+1;
        }
        return i;
    }
};//162
