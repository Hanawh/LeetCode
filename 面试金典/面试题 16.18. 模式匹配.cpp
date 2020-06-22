class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int len_s = value.size();
        int len_p = pattern.size();
        if(len_s == 0 and len_p <= 1) return true;
        if(len_s == 0) return false;
        if(len_p == 0) return false; 
        //计算模式a、b的次数
        int num_a = 0, num_b = 0;
        for(auto &p : pattern)
        {
            if(p == 'a') num_a ++;
            else num_b ++;
        }

        char char_start = 'b';
        int num_start = num_b, num_another = num_a;
        if(pattern[0] == 'a'){
            char_start = 'a';
            num_start = num_a;
            num_another = num_b;
        }

        int max_start = len_s / num_start;
        if(num_another == 0){
            string str = value.substr(0, max_start);
            string res;
            while(num_start--) res = res + str;
            if(res == value) return true;
            return false;
        }

        string start, another;
        for(int i = 0; i <= max_start; ++i){
            //计算另一个模式的长度
            int res = len_s - num_start * i;
            if(num_another == 0 or res % num_another) continue;
            int len_another = res / num_another;

            for(int j = 0; j < len_p; ++j){
                if(pattern[j] == char_start) continue;
                another = value.substr(i*j, len_another);
                break;
            }

            start = value.substr(0, i);

            //是否匹配
            string str;
            for(int j = 0; j < len_p; ++j){
                if(pattern[j] == char_start) str = str + start;
                else str = str +  another;
            }

            if(str == value) return true;
        }
        return false;
    }
};
