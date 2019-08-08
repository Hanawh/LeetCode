/*
输入: "   -42"
输出: -42

输入: "4193 with words"
输出: 4193

输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。因此无法执行有效的转换。

输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−231) 。
 */
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0; // 字符串是否为空
        int index = str.find_first_not_of(' '), sign = 1;
        long long num = 0;
        if(index < 0) return 0; //仅包含空白字符时
        if (str[index] == '+' || str[index] == '-') sign = str[index++] == '+' ? 1 : -1;
        else if(!isdigit(str[index])) return 0; //第一个非空格字符不是一个有效整数字符
        while(index < str.size() && isdigit(str[index])){
            num = num * 10 + (str[index++] - '0');
            if (num > (INT32_MAX)) return sign == -1 ? INT32_MIN : INT32_MAX;
        }
        cout<<sign<<num<<endl;
        return num * sign;
    }
};
int main(){
    string s;
    while (getline(cin, s)){
        cout << Solution().myAtoi(s) << endl;
    }
    return 0; 
}
