class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        unordered_set<char> tmp;
        int i=0,j=0,res=0;
        while(i<len and j<len){
            if(!tmp.count(s[j])){
                tmp.insert(s[j++]);
                res = max(j-i,res);
            }
            else tmp.erase(s[i++]);
        }
        return res;
    }
};//60ms 13.7MB

//优化
