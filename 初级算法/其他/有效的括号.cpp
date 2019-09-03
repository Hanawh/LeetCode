/*
输入: "()"
输出: true

输入: "([)]"
输出: false

输入: "{[]}"
输出: true
*/
#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char> temp;
        map<char, char> sign = {{')', '('}, {'}', '{'},{']', '['}};
        char c;
        for(auto i = 0; i < s.size(); ++i){
            if(s[i] == '(' | s[i] == '{' | s[i] == '['){
                temp.push(s[i]);
            }
            else{
                if(temp.empty()) return false;
                if(temp.top() != sign[s[i]]) return false;
                else{
                    temp.pop();
                }
            }
        }
        if(temp.empty()) return true;
        else return false;
    }
};

int main(){
    string str = "([)]";
    cout << boolalpha << Solution().isValid(str) << endl;
    return 0;
}
