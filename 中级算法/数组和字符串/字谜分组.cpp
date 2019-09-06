/*
输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> group;
        for(auto& s : strs){
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto& m : group) 
            result.push_back(m.second);
        return result; 
    }
};

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for (auto& i : Solution().groupAnagrams(strs)){
        for (auto& j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
