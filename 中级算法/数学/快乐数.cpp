/*
输入: 19
输出: true
解释: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/
#include<iostream>
using namespace std;
class Solution {
public: //非快乐数最终都会进入4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 的循环中
    bool isHappy(int n) {
        int temp = 0;
        while(n != 1){
            int sum = 0;
            while(n != 0){
                sum += (n%10)*(n%10);
                n /= 10;
            }
            if(sum == 4) return false;
            n = sum;
        }
        return true;
    }
};

int main(){
   int x;
   while(cin >> x){
       cout << boolalpha << Solution().isHappy(x) << endl;
   }
}
