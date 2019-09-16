/*
输入: dividend = 10, divisor = 3
输出: 3

输入: dividend = 7, divisor = -3
输出: -2
*/
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
       long long res = 0;
        long long divd = labs(dividend), divs = labs(divisor);
        int pos = (dividend < 0) ^ (divisor < 0);
        long long mod = (long long)INT_MAX + 1;
        if (divd < divs) return 0;
        while (divs <= divd)
        {
            long long mul = 1, tmp = divs;
            while ((tmp << 1) <= divd)
            {
                mul <<= 1; tmp <<= 1;
            }
            res += mul; divd -= tmp;
            if (res == mod) break;
        }
        if (pos == 0 and res == mod) res -= 1;
        return pos == 0 ? res : -res;
    }
};
