/*
写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
public: 
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        for(auto i = 1; i <= n; ++i){
            if(i%3 == 0 && i%5 == 0) result[i-1] = "FizzBuzz";
            else if (i%3 == 0) result[i-1] = "Fizz";
            else if (i%5 == 0) result[i-1] = "Buzz";
            else{
                result[i-1] = to_string(i);
            }
        }
        return result;
    }
};

int main(){
    int n;
    vector<string> result;
    while(cin >> n){
        result = Solution().fizzBuzz(n);
        for(auto &i : result){
            cout << i << endl;
        }
    }
}
