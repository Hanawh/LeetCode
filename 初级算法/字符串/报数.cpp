/*
1.     1
2.     11
3.     21
4.     1211
5.     111221

输入: 4
输出: "1211"
 */
#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        string res;
        for(int i = 1; i < n; ++i){
            res = "";
            int count = 1;
            for (int j = 1; j < s.size(); ++j)
            {
                if(s[j] != s[j-1]){
                    res += to_string(count) + s[j-1]; //to_string
                    count = 0;
                }
                ++count;
            }
            res += to_string(count) + *(s.rbegin()); //s.rbegin()指向最后一个字符
            s = res;
        }
        return s;
    }
};
int main(){
    int n;
    while (cin >> n){
        cout << Solution().countAndSay(n) << endl;
    }
    return 0; 
}
