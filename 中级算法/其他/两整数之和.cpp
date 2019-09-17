class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0) return a;    //负数以补码形式储存
        long long sum = a ^ b;       
        long long carry = (a & b & 0xffffffff) << 1;      //阶段超出范围的进位
        return getSum(sum, carry);
    }
};
