class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int len = stones.size();
        if(len == 1) return stones[0];
        for(int i = 0; i < len-1; ++i){
            sort(stones.rbegin(), stones.rend());
            stones[0] -= stones[1];
            stones[1] = 0;
        }
        return stones[0];
    }
};//8ms 8.7M
