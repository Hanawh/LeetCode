class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //得到每个区间的和
        int sum = accumulate(nums.begin(), nums.end(), 0);  
        if(sum%k!=0) return false;
        sum = sum / k;

        int len = nums.size();
        vector<int> state(len); // 记录是否被分配过

        return dfs(0, 0, k, nums, state, sum);
    }

    bool dfs(int start, int sum, int k, vector<int>& nums, vector<int>& state, int target){
        // start 代表从哪里找
        // sum 代表当前累计和
        // k代表还剩几个子集需要找
        if(k==1) return true;
        bool flag = false;
        for(int i=start; i<nums.size(); ++i){
            if(!state[i] && sum+nums[i]<=target){
                state[i] = 1;
                if(sum+nums[i]==target) flag = dfs(0, 0, k-1, nums, state, target); //剩下的数是否可以凑到k-1等分
                else flag = dfs(start+1, sum+nums[i], k, nums, state, target);
                if(flag) return true;
                state[i] = 0;
            }
        }
        return flag;
    }
};
