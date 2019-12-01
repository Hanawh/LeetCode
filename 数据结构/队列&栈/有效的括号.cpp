/*
Input: "()"
Output: true

Input: "(]"
Output: false
*/

#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char> temp;
        unordered_map<char,char> map = {{')', '('}, {'}', '{'},{']', '['}};
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '(' or s[i] == '{' or s[i] == '['){
                temp.push(s[i]);
            }
            else{
                if(temp.empty()) return false;
                if(map[s[i]] != temp.top()) return false; 
                else temp.pop();
            }
        }
        if(temp.empty()) return true;
        else return false;
    }
};
