#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
		vector<int> next(len);
		for(int i = 1; i < len; ++i){
			int k = next[i-1]; //应该比较的对象
			while(k and s[i] != s[k]){
				k = next[k-1];
			}
			if(s[i] == s[k]) next[i] = k + 1;
		}
		int res = next[len-1];
		if(len%(len-res) == 0) return true;
		return false;
    }
};
