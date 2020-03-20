class Solution {
public:
     int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(char &c:s){
            m[c]++;
        }

        int len = 0;
        for(auto item:m){
            if(item.second%2==0) len+=item.second;
            else{
                len+=item.second-1;
            }
        }
        return len<s.size()?len+1:len;
    }
};
