class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int len = A.size();
        int sum = 0,temp1 = 0, temp2 = -101;
        for(int i = 0; i < len; ++i){ 
            if(A[i] < 0){
                if(K != 0){
                    sum += -A[i]; 
                    K--;
                }
                else{
                    sum += A[i];
                }
            }
            else if(A[i] == 0){
                K = 0;
            }
            else{ 
                if(K != 0){
                    if(K % 2 == 0){
                        sum += A[i];
                    }
                    else{
                        temp1 = -A[i];
                        if(i-1 >= 0) temp2 = -abs(A[i-1]) + A[i-1] + A[i];
                        sum += max(temp1,temp2);
                    }
                    K = 0;
                }
                else{
                    sum += A[i];
                }
            }
        }
        return sum;
    }
};//8 ms 9.1MB
