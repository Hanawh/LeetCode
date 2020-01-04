class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int flag = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'R') flag++;
            else flag--;
            if(flag == 0) res++;
        }
        return res;
    }
};
