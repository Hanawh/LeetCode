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

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q; //默认是大顶堆
        for(int v : stones) q.push(v);
        while(q.size()>=2){
            int top1 = q.top();q.pop();
            int top2 = q.top();q.pop();
            if(top1-top2) q.push(top1-top2);
        }
        return q.size() == 1 ? q.top() : 0;
    }
};//4ms 8.7M


