class Solution {
public:
    int translateNum(int num) {
        if(num >= 0 and num < 10) return 1;
        int flag = 0;
        if(num % 100 <= 25 and num % 100 > 9) flag = 1;
        return translateNum(num/10) + flag * translateNum(num/100);
    }
};
