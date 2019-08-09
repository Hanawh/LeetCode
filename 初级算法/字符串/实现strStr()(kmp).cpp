/*
输入: haystack = "hello", needle = "ll"
输出: 2

输入: haystack = "aaaaa", needle = "bba"
输出: -1
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.size() < needle.size()) return -1;
        if(haystack.size() == needle.size()) return haystack==needle? 0 : -1;
        /*
         for (int i = 0; i <= haystack.size() - needle.size(); ++i)
        {
            if (haystack.substr(i, needle.size()) == needle) return i;
        }
        return -1;
         */
        //求next数组
        int plen = needle.size();
        int k = -1, j = 0; //needle[k]代表前缀 needle[j]代表后缀
        int next[plen];
        next[0] = -1;
        while(j<plen-1){
            if(k == -1 || needle[j] == needle[k]){
                ++k;
                ++j;
                if(needle[j] != needle[k]) { //needle[j]是下一个要比的
                    next[j] = k;
                }
                else{
                    next[j] = next[k];
                }
            }
            else{
                k = next[k]; //自己与自己匹配
            }
        }
        //匹配
        k = 0, j = 0;
        while(k < haystack.size() && j < plen){
            if(j == -1 || haystack[k] == needle[j]){
                ++k;
                ++j;
            }
            else{
                j = next[j];
            }
        }
        if (j == plen){
            return k-plen;
        }
        else return -1;
    }
};
int main(){
    string s, p;
    while (cin >> s >> p){
        cout << Solution().strStr(s, p) << endl;
    }
    return 0; 
}
