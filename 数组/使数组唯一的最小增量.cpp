class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0;
        for(int i=1; i<A.size(); ++i){
           if(A[i]<=A[i-1]){
               int temp = A[i];
               A[i] = A[i-1]+1;
               res += A[i]-temp;
           }
        }
        return res;
    }
};
