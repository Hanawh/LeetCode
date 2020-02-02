class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            int tmp = abs(nums[i]);
            if(nums[tmp-1]>0) nums[tmp-1] *= -1;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]>0) res.push_back(i+1);
        }

        return res;
    }
};//60ms 16.3MB
