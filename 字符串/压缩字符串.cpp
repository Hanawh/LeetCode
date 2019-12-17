class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.empty()) return 0;
        char pre;
        int num;
        int k = 0;
        for(int i = 0;i < chars.size(); ++i){
            if(i == 0){
                pre = chars[i];
                num = 1;
                continue;
            }
            if(chars[i] == pre){
                num ++; 
            }
            else
                chars[k] = pre;
                if(num != 1){
                    string s;
                    while(num){
                        s = char('0'+num%10)+s;
                        num /= 10;
                    }
                    chars[k] = pre;
                    for(auto i : s){
                        chars[++k] = i;
                    }
                }
                ++k;
                num = 1;
            }
            pre = chars[i];
        }

        chars[k] = pre;
        if(num != 1){
            string s;
            while(num){
                s = char('0'+num%10)+s;
                num /= 10;
            }
            for(auto i : s){
                chars[++k] = i;
            }
        }
        ++k;
        return k;
    }
};
