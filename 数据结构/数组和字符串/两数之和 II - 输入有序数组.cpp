class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         map<int, int> temp;
        for(int i=0; i<nums.size(); ++i)
        {
            if(temp.count(target-nums[i])) 
            return {temp[target-nums[i]]+1, i+1};
            temp[nums[i]]=i; 
        }
        return {};
    }
};
