/*
以下方法超时，开始想的是二维数组处理，判断连续。难点在于如何处理两个相同的子串。
将符合要求的子串按开始字符归类，重复的元素需要去重，每类的元素个数必然等于最大长度元素的长度。因此只需要统计每类元素的最大长度即可。
*/
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int len = p.size();
        if(len <= 1) return len;
        vector<vector<int> > dp(len, vector<int>(len));
        //初始化对角线
        for(int i=0; i<len; ++i){
            dp[i][i] = 1;
        }
        unordered_set<string> res;
        //斜着遍历
        for(int l=1; l<len; ++l){
            for(int i=0; i<len-l; ++i){
                int j=i+l;
                if(l==1) { //判断相邻元素是否连续 z a i<j
                    if((p[i]=='z' and p[j]=='a') or (p[j] - p[i]==1)){
                        dp[i][j] = 1;
                    } 
                }
                else{
                    dp[i][j] = (dp[i][j-1] and dp[i+1][j]);
                }
                if(dp[i][j]==1){ //去重
                    res.insert(p.substr(i, j-i+1));
                }
            }
        }
        for(int i=0; i<len; ++i){
            res.insert(p.substr(i, 1));
        }
        return res.size();
    }
};

class Solution {
public:
    bool isContinous(char prev, char curr) {
        if (prev == 'z') return curr == 'a';
        return prev + 1 == curr;
    }
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26);
        int N = p.size();
        int k = 0;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && isContinous(p[i - 1], p[i])) {
                ++k;
            } else {
                k = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
