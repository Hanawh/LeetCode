#include<iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            ++count;
            n = n & (n-1); //剑指offerP102 
            //将一个整数减去1之后和原来的数相与，结果相当于把整数的二进制表示中最右边的1变为0
        }
        return count;
    }
};

int main(){
    uint32_t n;
    while (cin >> n){
        cout << Solution().hammingWeight(n) << endl;
    }
}
