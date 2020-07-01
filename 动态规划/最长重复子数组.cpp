class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int lenA = A.size();
        int lenB = B.size();

        vector<vector<int> > tb(lenB, vector<int>(lenA));
        for(int i=0; i<lenB; i++) {if(B[i] == A[0]) tb[i][0] = 1;}

        for(int i=0; i<lenA; i++) {if(B[0] == A[i]) tb[0][i] = 1;}
        
        int res = INT32_MIN;
        for(int i=1; i<lenB; i++){
            for(int j=1; j<lenA; j++){
                if(B[i] == A[j]){
                    tb[i][j] = tb[i-1][j-1] + 1;
                }

                if(tb[i][j] > res) res = tb[i][j];
            }
        }
        return res;
    }
};
