/*
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
		for(int i=0;i<magazine.size();++i){
			map[magazine[i]] ++;
		}
		for(int i=0;i<ransomNote.size();++i){
			if(map.find(ransomNote[i]) == map.end() || map[ransomNote[i]] == 0) return false;
			map[ransomNote[i]] --;
		}
		return true;
    }
};
/*
map找的过程中会比较消耗时间，可以用26个大小的数组来保存
*/
