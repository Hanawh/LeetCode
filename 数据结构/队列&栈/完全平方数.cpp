/*
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
*/

#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        unordered_set<int> hash;
        q.push(n);
        hash.insert(n);
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            step++;
            for(int i = 0; i < size; ++i){
                int cur = q.front();
                if(cur==0) return step;
                //扩展节点 用差值作为节点
                //找出小于其的数
                for(int j=1; j*j <= cur; ++j){
                    int next = cur - j*j;
                    if(next==0) return step;
                    if(!hash.count(next)){ //如果没有被访问
                        q.push(next);
                        hash.insert(next);
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};

int main(){
    cout<<Solution().numSquares(12)<<endl;
}
