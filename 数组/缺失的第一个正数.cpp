class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       //置换 [1,N]
       int n = nums.size();
       for(int i = 0; i < n; ++i){
           while(nums[i] >= 1 and nums[i] <= n and nums[i] != nums[nums[i]-1]){ //交换后的值可能也在范围内
               int temp = nums[i];
               if(temp == i+1) break;
               nums[i] = nums[temp-1]; 
               nums[temp-1] = temp;
           }
       }
       for(int i = 0; i < n; ++i){
           if(nums[i] != i+1) return i+1;
       }
       return n+1;
    }
};
