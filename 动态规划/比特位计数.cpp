class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        int start = 1;
        for(int i=1; i<num+1; ++i){
            if(i == start) {
                res[i] = 1;
                start *= 2;
            }
            else if(i < start){
                res[i] = res[start/2] + res[i-start/2];
            }
            else{
                res[i] = res[start] + res[i-start];
            }
        }
        return res;
    }
};
