#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution1 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int i = 0, j = 0;
        while (i < g.size() and j < s.size())
        {
            if(s[j] >= g[i]){
                j++;
                i++;
                res++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};


class Solution2 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(s.begin(), s.end());
        for(int i = 0; i < g.size(); ++i){
            for(int j = 0; j < s.size(); ++j){
                if(s[j] >= g[i]){
                    res++;
                    s[j] = -1;
                    break;
                }
            }
        }
        return res;
    }
};
