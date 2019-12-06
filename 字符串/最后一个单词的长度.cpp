/*
58 最后一个单词的长度
输入: "Hello World"
输出: 5
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        while(*(s.end()-1) == ' ') {
            s = s.substr(0, len-1);
            len--;
        }
        int pos = s.find_last_of(' ');
        if(pos == s.npos) return len;
        return len-pos-1;
    }
};
