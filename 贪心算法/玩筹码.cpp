/*
输入：chips = [1,2,3]
输出：1
解释：第二个筹码移动到位置三的代价是 1，第一个筹码移动到位置三的代价是 0，总代价为 1。
*/
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int even = 0, N = chips.size();
        for(auto n:chips) if((n&1)==0) even++;
        return min(even, N-even);
    }
};
