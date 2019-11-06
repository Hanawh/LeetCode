//输入: "Let's take LeetCode contest"
//输出: "s'teL ekat edoCteeL tsetnoc" 
#include<iostream>
#include<string>
#include<algorithm> //reverse
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
       int head = 0;
       for(int i=0; i<s.size(); ++i){
           if(s[i]==' '){
               reverse(s[head],s[i]);
               head = i+1;
           }
       }
       return s;
         
    }
};
