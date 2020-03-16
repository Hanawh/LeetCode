class Solution {
public:
    string compressString(string S) {
        string res;
        int len = S.size();
        char pre;
        int num=0;
        for(int i=0; i<len; ++i){
            if(i==0) {pre=S[i];num++;}
            else{
                if(S[i]==pre) num++;
                else{
                    res += pre;
                    res += to_string(num);
                    pre = S[i];
                    num = 1;
                }
            }
        }
        res += pre;
        res += to_string(num);
        res.size()<S.size()? res: res = S;
        return res;
    }
};
