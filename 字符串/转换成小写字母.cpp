class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0; i<str.size();++i){
            if(str[i]>='A' and str[i]<='Z'){
                str[i] = 'a'+int(str[i]-'A');
            }
        }
        return str;
    }
};
