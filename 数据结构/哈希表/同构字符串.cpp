class Solution {
public:
    bool isIsomorphic_(string s, string t) {
        unordered_map<char, char> m;
        for(int i = 0; i < s.size(); ++i){
            if(m.count(s[i])) {
                if(m[s[i]] != t[i])
                return false; 
            }
            else{
                m[s[i]]=t[i];
            }
        }
        return true;
    }

    bool isIsomorphic(string s, string t){
        return isIsomorphic_(s,t) and isIsomorphic_(t,s);
    }
};
