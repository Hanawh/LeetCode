class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res(2,-1);
        if(len == 0) return res;
        int i=0, j=len;
        //find left [left,right)
        while(i<j){ 
            int mid = i+(j-i)/2;
            if(nums[mid] == target) { //[left, mid)
                j = mid;
            }
            else if(nums[mid] < target){ 
                i = mid+1;
            }
            else if(nums[mid] > target){
                j = mid;
            }
        }
        // i=j
        if(i==len or nums[i]!=target) return res;
        res[0] = i;

        //find right [left,right)
        i=0, j=len;
        while(i<j){ 
            int mid = i+(j-i)/2;
            if(nums[mid] == target) { //[mid+1,right)
                i = mid+1;
            }
            else if(nums[mid] < target){ 
                i = mid+1;
            }
            else if(nums[mid] > target){
                j = mid;
            }
        }
        res[1] = j-1;
        return res;
    }
};
