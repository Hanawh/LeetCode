class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1; //key代表的是前缀和, 代表以当前位置为结尾, 之前的奇数个数; value是前缀和的个数, 意思是起点的可能性
        int res = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) //前缀和
        {
            sum += nums[i] & 1;
            m[sum]++;
            if(sum>=k) res+=m[sum-k];
        }
        return res;
    }
};
