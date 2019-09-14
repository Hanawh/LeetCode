/*
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...s
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public: 
    int titleToNumber(string s) {
        int result = 0;
        for(auto i = 0; i < s.size(); ++i){
            result = result * 26 + (s[i]-'A'+1);
        }
        return result;
    }
};

int main(){
   string s;
   while(cin >> s){
       cout << Solution().titleToNumber(s) << endl;
   }
   return 0;
}
