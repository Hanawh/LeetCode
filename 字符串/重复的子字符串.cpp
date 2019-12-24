class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        vector<int> next(len);
        next[0] = -1;
        int k = -1;//前缀
        int j = 0;
        while(j < len-1){
            if(k == -1 or s[j] == s[k]){
                k++;
                j++;
                next[j] = k;
            }
            else{
                k = next[k];
            }
        }
        if(s[j] == s[k] and len%(j-k) == 0) return true;
        return false;
    }
};
