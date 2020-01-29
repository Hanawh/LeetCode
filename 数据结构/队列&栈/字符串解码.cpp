/*
s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef"
*/ 
class Solution {
public:
    string decodeString(string s) {
        stack<int> digit;
        stack<string> str;
        string temp;
        int num = 0;
        for(int i = 0; i < s.size(); ++i){ 
            if(s[i]-'0'>=0 and s[i]-'0'<=9){
                num = 10 * num + s[i] - '0';
            }
            else if(s[i] == '['){
                digit.push(num);
                num = 0;
                str.push(temp);
                temp.clear();
            }
            else if(s[i] == ']'){ //出栈
                int num = digit.top();
                digit.pop();
                
                while(num--){
                    str.top() += temp; 
                }

                temp = str.top();
                str.pop();
            }
            else temp += s[i];
        }
        return temp;
    }
};
