class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        // 当第一次选取的某一个值，删除了它的邻居，为了获得最大点数，我们下一次还是会选择删除该数
        // 统计每个数出现的个数
        int max_val = 0;
        for(auto &i : nums){
            max_val = max(max_val, i);
        }

        vector<int> time(max_val+1);
        for(auto &i : nums){
           time[i]++;
        }

        vector<int> tb(max_val+1);
        tb[1] = time[1];
        //选该数 ：tb[i] = tb[i-2] + i*time[i];
        //不选该数 ：tb[i] = tb[i-1];
        for(int i=2; i<max_val+1; i++){
            tb[i] = max(tb[i-1], tb[i-2]+i*time[i]);
        }
        return tb[max_val];
    }
};
