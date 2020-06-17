class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
      int maxval = A[0];
      int res = 0;
      for(int j = 1; j < A.size(); ++j){
        int tmp = A[j] - j;
        res = max(res, tmp + maxval);
        maxval = max(maxval, A[j]+j);
      }
      return res;
    }
};
