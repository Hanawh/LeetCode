class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m;
        int res=0;
        for(auto &i:A){
            for(auto &j:B){
                m[i+j]++;
            }
        }

        for(auto &i:C){
            for(auto &j:D){
                if(m.count(-i-j)) res+=m[-i-j];
            }
        }
        return res;
    }
};
