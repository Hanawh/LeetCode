//输入: "the sky is blue"
//输出: "blue is sky the"
class Solution {
public:
    string reverseWords(string s) {
        string result;
        stack<string> temp;
        string str;
        for(int i=0; i<s.size(); ++i){
            if(s[i] != ' '){
                str += s[i];
            }
            else{
                if(str.size()!=0){
                    temp.push(str);
                    str.clear();
                }
                else{
                    continue;
                }
            }
        }
        if(str.size()!=0) temp.push(str);
        int len = temp.size();
        for(int i=0; i<len; ++i){
            if(i != len - 1){
                result += temp.top()+' ';
            }
            else{
                result += temp.top();
            }
            temp.pop();
        }
        return result;
    }
};
