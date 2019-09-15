/*
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
由于返回类型是整数，小数部分将被舍去。
*/
#include<iostream>
using namespace std;
class Solution {
public: 
    int mySqrt(int x) {
        if(x <= 1) return x;
        int left = 0, right = x;
        int mid;
        while(left < right){
            mid = (left + right)/2;
            if(x/mid == mid) return mid; //防止溢出
            if(x/mid > mid){ 
                left = mid + 1;
            }
            else{
                right = mid; //结果应在right 或者 mid取得
            }
        }
        return right-1;
    }
};
