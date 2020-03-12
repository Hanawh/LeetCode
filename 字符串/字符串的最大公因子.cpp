class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        int l = min(len1,len2);
        for(int i = l; i>=1; i--){
            if(len1%i==0 and len2%i==0){
                string str = str1.substr(0,i);
                if(gcd(str1,str) and gcd(str2,str)) return str; 
            }
        }
        return "";
    }

    bool gcd(string A, string B){
        int len1 = A.size();
        int len2 = B.size();
        int len = len1 / len2;
        string str;
        for(int i = 1; i <= len; ++i){
            str += B;
        }
        return str == A;
    }
};
