class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> s;
        for(char &c:chars){
            s[c]++;
        }
        
        int cnt=0;
        int flag;
        for(int i=0; i<words.size(); ++i){
            flag = 0;
            unordered_map<char,int> temp = s;
            for(auto &c:words[i]){
                if(temp[c]>0){ //count的返回值要么是0，要么是1
                    temp[c]--;
                }
                else{
                    flag = 1;
                    break;
                }
                
            }
            if(flag == 0) cnt += words[i].size();
        }
        return cnt;
    }
};
