/*
输入: a = "11", b = "1"
输出: "100"
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int m = a.size() - 1;
        int n = b.size() - 1;
        int sum = 0, carry = 0;
        while(m >= 0 || n >= 0){
            if(m >=0 && n >= 0) sum = (a[m]-'0') + (b[n]-'0');
            else if(m >= 0) sum = (a[m]-'0');
            else sum = (b[n]-'0');
            sum += carry;
            s = to_string(sum%2) + s;
            carry = sum/2;
            m--;
            n--;
        }
        return carry == 1 ? "1" + s : s;
    }
};
