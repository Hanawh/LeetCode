class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        for(int i = 0; i < len; ++i){
            if(i != 0 and nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = len - 1;
            while(left < len and right < len and left < right){
                if(left != i+1 and nums[left] == nums[left-1]){   
                    left++;
                }
                else{
                    if(nums[i] + nums[left] + nums[right] == 0){
                        res.push_back({nums[i], nums[left], nums[right]});
                        left++;
                    }
                    else if(nums[i] + nums[left] + nums[right] < 0)
                    {
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
