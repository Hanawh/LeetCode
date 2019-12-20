class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        if(len == 1) return s;
        auto a = s.begin();
        auto b = s.end();
        int i = 0;
        while(i < len)
        {   
            if(i+k > len) reverse(a,b);
            else reverse(a, a+k);
            if(i+2*k < len) a += 2*k;
            i += 2*k;
        }
        return s;
    }
};
