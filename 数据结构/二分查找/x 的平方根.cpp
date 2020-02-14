class Solution {
public:
    int mySqrt(int x) {
        long i=1, j=x/2;
        while(i<=j){
            long mid = i+(j-i)/2;
            long cur = mid * mid;
            long next = (mid+1)*(mid+1);
            if(cur <= x and next > x) return mid;
            else if(cur < x) i=mid+1;
            else j=mid;
        }
        return x;
    }
};//69
