/*
输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public: 
    int evalRPN(vector<string>& tokens) {
        stack<int> temp;
        for (auto& token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/") //先判断是数字的话不能通过stoi转换
            {
                int top1 = temp.top(); temp.pop();
                int top2 = temp.top(); temp.pop();
                if (token == "+") temp.push(top2 + top1);
                else if (token == "-") temp.push(top2 - top1);
                else if (token == "*") temp.push(top2 * top1);
                else if (token == "/") temp.push(top2 / top1);
            }
            else
            {
                temp.push(stoi(token));
            }
        }
        return temp.top();
    }
};

int main(){
    vector<string> str = {"2", "1", "+", "3", "*"};
    cout << Solution().evalRPN(str) << endl;
    return 0;
}
