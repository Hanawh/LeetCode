/*
392 判断子序列
s = "abc", t = "ahbgdc"
返回 true.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pre = -1;
        int cur;
        for(int i = 0; i < s.size(); ++i){
            cur = t.find_first_of(s[i], pre+1); //若没有找到 则返回string.npos
            if(cur == t.npos){
                return false;
            }
            if(cur < pre){
                return false;
            }
            pre = cur;
        }
        return true;
    }
};
