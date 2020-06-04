class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len), right(len);
        for(int i = 0; i < len; ++i){
            if(i == 0) left[i] = 1;
            else
            {
                left[i] = left[i-1] * nums[i-1];
            }
        }
        for(int j = len-1; j >= 0; j--){
            if(j == len-1) right[j] = 1;
            else{
                right[j] = right[j+1] * nums[j+1]; 
            }
        }

        for(int k = 0; k < len; ++k){
            left[k] *= right[k];
        }
        return left;
    }
};
