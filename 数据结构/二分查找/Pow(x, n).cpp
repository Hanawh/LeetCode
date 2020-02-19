class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(n==1) return x; 
        long long N=n;
        if(N<0){
            x = 1/x;
            N = -N;
        }
        double half = myPow(x,N/2);
        if(N%2 == 1) return x*half*half;
        else return half*half;
    }
};
