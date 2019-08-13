/*
输入: ["flower","flow","flight"]
输出: "fl"

输入: ["dog","racecar","car"]
输出: ""
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        if (strs.size() < 1) return s;
        for(int i = 0; i < strs[0].size(); ++i){
            char c = strs[0][i]; int count = 0;
            for (int j = 1; j < strs.size(); ++j)
            {
                if(i+1 > strs[j].size()) return s; 
                if(strs[j][i] == c) ++count;
            }
            if(count == strs.size()-1) s.push_back(c);
            else return s;
        }
        return s;
    }
};
int main(){
    vector<string> strs;
    string s;
    while (cin >> s){
        strs.push_back(s); //最后一个单词输入后 回车->ctrl+z+回车
    }
    cout << Solution().longestCommonPrefix(strs) << endl;
    return 0; 
}
