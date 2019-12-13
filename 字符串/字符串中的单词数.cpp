class Solution {
public:
    int countSegments(string s) {
        if(s.empty()) return 0;
        int len = s.size();
        int pre = 0; //代表前一个是符号
        int res = 0;
        for(int i = 0; i < len; ++i){
           if(pre == 0 and s[i] != ' ')
           {
               res++;
               pre = 1;
           }
           else if(s[i] == ' '){
               pre = 0;
           }
        }
        return res;
    }
};
