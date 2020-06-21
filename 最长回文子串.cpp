class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<bool> > table(len, vector<bool>(len, false));
        int maxlen = 1;
        int start = 0;
        //定义table[i][j]为i到j是否为回文串
        //初始化对角线
        for(int i = 0; i < len; i++){
          table[i][i] = true;
        }
        for(int j = 1; j < len; j++){
          for(int i = 0; i < j; i++){
            if(s[j] == s[i]){
              table[i][j] = (j - i < 3 ? true : table[i + 1][j - 1]);
            }

            //记录最长
            if(table[i][j] and j-i+1 > maxlen) {
              maxlen = j-i+1;
              start = i;
            }
          }
        }
        return s.substr(start, maxlen);
    }
};
