/*
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i >= 0; i--){
            if((++digits[i])%10) return digits;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
int main(){
    int a[3] = {1, 2, 3};
    vector<int> v(a, *(&a + 1));
    for(auto &i:Solution().plusOne(v)){
        cout << i;
    }
    return 0;
}
