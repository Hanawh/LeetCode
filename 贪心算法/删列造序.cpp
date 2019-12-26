class Solution {
public:
    int minDeletionSize(vector<string>& A) {
         int num = A.size();
        if(num <= 1) return 0;
        int res = 0;
        int len = A[0].size();
        for(int i = 0; i < len; ++i){
            for(int j = 1; j < num; ++j){
                if(A[j][i] < A[j-1][i]){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
