class Solution {
public:
      int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        if(len2 == 0) return 0;
        if(len1 < len2) return -1;
        if(len1 == len2) return haystack==needle? 0 : -1;
        //计算next数组
        vector<int> next = calNext(needle);
        //匹配
        int k=0, j=0;
        while (k<len1 && j<len2){
            if(j==-1||haystack[k] == needle[j]){
                ++j;
                ++k;
            }
            else{
                j=next[j];//如果等于-1
            }
            if(j==len2){
                break;
            }
        }
        if(j==len2) return k-len2;
        else return -1;
    }

    vector<int> calNext(string& s){
        int len = s.size();
        vector<int> next(len);
        int k=-1;//前缀
        int j=0;//后缀
        next[0]=-1;
        while(j<len-1){
            if(k==-1||s[j]==s[k]){
                ++k;//前缀下一个 即匹配不成功要跳转的索引
                ++j;
                next[j] = k; //less time 
            }
            else{
                k=next[k];//自我匹配 0～k相当于模式串
            }
        }
        return next;
    }  
};
