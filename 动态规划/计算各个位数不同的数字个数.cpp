class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1; 
        if(n == 1) return 10;
        int start = 10;
        int res = 9;
        int i = 2;
        int tmp;
        while(i <= n){
            res = res * (11-i);
            tmp = start + res;
            start = tmp;
            i++;
        }
        return tmp;
    }
};
