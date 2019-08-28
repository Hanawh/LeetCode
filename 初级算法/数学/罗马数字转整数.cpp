/*
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
通常情况下，罗马数字中小的数字在大的数字的右边。
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/

#include<iostream>
#include<map>
using namespace std;
class Solution{
public: 
    int romanToInt(string s) {
        map<char, int> s_dict = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        for(auto i = 0; i < s.size(); ++i){
            if(i+1 >= s.size() || s_dict[s[i]] >= s_dict[s[i+1]]){
                result += s_dict[s[i]];
            }
            else{
                result -= s_dict[s[i]];
            }
        }
        return result;
    }
};

int main(){
    string s;
    while(cin >> s){
        cout << Solution().romanToInt(s) << endl;
    }
    return 0;
}
