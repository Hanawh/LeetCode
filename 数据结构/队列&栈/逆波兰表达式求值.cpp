/*
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
*/

#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> temp;
        for(auto &str : tokens){
            if (str == "+" || str == "-" || str == "*" || str == "/"){
                int num1 = temp.top(); temp.pop();
                int num2 = temp.top(); temp.pop();
                if(str == "+") temp.push(num1+num2);
                else if(str == "-") temp.push(num2-num1);
                else if(str == "*") temp.push(num1*num2);
                else if(str == "/") temp.push(num2/num1);
            }
            else{
                temp.push(stoi(str));
            }
        }
        return temp.top();
    }
};
