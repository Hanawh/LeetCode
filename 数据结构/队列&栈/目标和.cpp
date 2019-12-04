class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        DFS(nums, S, 0, 0, count);
        return count;
    }

    void DFS(vector<int>& nums, int S, int sum, int i, int& count){
        if(i == nums.size()){
            if(sum == S){
                ++count;
            }
        }
        else{
            DFS(nums, S, sum+nums[i], i+1, count);
            DFS(nums, S, sum-nums[i], i+1, count);
        }
    }
};
