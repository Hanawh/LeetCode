/*
输入: 00000010100101000001111010011100
输出: 00111001011110000010100101000000
解释: 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
      因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。
*/
#include<iostream>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0;
        uint32_t res = 0;
        while (i < 32){
            int temp = n & 0x01;
            n = n >> 1;
            res = res << 1;
            res |= temp;
            ++i;
        }
        return res;
    }
};

int main(){
   uint32_t x;
   while(cin >> x){
       cout << Solution().reverseBits(x) << endl;
   }
}
