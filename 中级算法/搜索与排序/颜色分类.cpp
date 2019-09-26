class Solution {
public:
     void sortColors(vector<int>& nums) {
        int size = nums.size();
        int p=0, q=0, r=size-1;
        while (q <= r){
           if(nums[q] > nums[r]){ //nums[q] 0 or 1
               exchange(nums[q], nums[r]);
           }
           if(nums[q] == 0){
               exchange(nums[q], nums[p]); //nums[q] 1;
           }
           if(nums[p] == 0){
               p++;
           }
           if(nums[r] == 2){
               r--;
           }
           if(nums[q] == 1 or nums[q] == 0){
               q++;
           }
        }
        
    }

    void exchange(int &s, int &t){
        if(s == t) return;
        int temp = s;
        s = t;
        t = temp;
    }
};
