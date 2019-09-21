/*
输入: numerator = 2, denominator = 3
输出: "0.(6)"
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public: 
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string result;
        if (numerator > 0 ^ denominator > 0) result += '-';
        long long num = abs((long long)numerator);
        long long den = abs((long long) denominator);
        result += to_string(num / den);
        long long remainder = num % den;
        if(remainder == 0) return result;
        result += ".";

        //记录小数点的位置
        int pos = result.length();
        int temp = 0; //记录位置
        map<int, int> mapping;
        while(remainder){
            if(mapping.find(remainder) != mapping.end()){
                temp = mapping[remainder];
                //加括号
                result.insert(result.begin() + temp, '(');
                result += ')';
                break;
            }
            mapping[remainder] = pos++;
            result += to_string(10 * remainder / den);
            remainder = (10 * remainder) % den;
        }
        return result;
    }
};
