class Solution {
public:
    bool checkRecord(string s) {
        int tag_a = 0;
        int tag_l = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == 'L') {
                tag_l++;
                if(tag_l > 2) return false;
            }
            else{
                tag_l = 0;
                if(s[i] == 'A') tag_a++;
                if(tag_a > 1) return false;
            }
        }
        return true;
    }
};
