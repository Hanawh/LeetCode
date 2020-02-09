class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s(J.begin(),J.end());
        int num = 0;
        for(int i=0; i<S.size(); ++i){
            if(s.count(S[i])) num++;
        }
        return num;
    }
};
