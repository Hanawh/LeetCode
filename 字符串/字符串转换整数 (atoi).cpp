class Solution {
public:
    int myAtoi(string str) {
        int len = str.size(); 
        //空串
        if(len == 0) return 0;
        int cur = 0;
        //全是空格
        while(cur<len and str[cur]==' '){
            cur++;
        }
        if(cur==len) return 0;
        //第一个字符非有效
        bool neg = false;
        if(str[cur]=='-'){
            neg = true;
            cur++;
        }
        else if(str[cur]=='+'){
            cur++;
        }
        else if(!isdigit(str[cur])){
            return 0;
        }

        int res = 0;
        while(cur<len and isdigit(str[cur])){
            int tmp = str[cur]-'0';
            //判断是否超出范围
            if(res > (INT32_MAX - tmp) / 10){
                return neg ? INT32_MIN : INT32_MAX;
            }
            res = res * 10 + tmp;
            cur++;
        }
        return neg ? -res : res;
    }
};
