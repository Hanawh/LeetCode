/*
输入: "hello"
输出: "holle"
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        vector<pair<int, char> > map;
		//找出元音位置
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
				map.push_back(make_pair(i, s[i]));
			}
		}
		//替换
		for(int i = 0; i < map.size(); ++i){
			int j = map.size()-i-1;
			int first = map[i].first;
			char second = map[j].second;

			s[first] = second;
		}
		return s;
    }
};
