class Solution {
public:
    int minDistance(string word1, string word2) {
        int lenA = word1.size();
        int lenB = word2.size();
        if(lenA * lenB == 0) return lenA+lenB;
        int db[lenA+1][lenB+1];
        //初始化 空串和任意一个串的距离都是另一个串的长度
        for(int i=0; i<lenA+1; ++i){
            db[i][0] = i;
        }

        for(int j=0; j<lenB+1; ++j){
            db[0][j] = j;
        }

         for(int i=1; i<lenA+1; ++i){
             for(int j=1; j<lenB+1; ++j){
                 int remove = db[i-1][j]+1; //删: 已知"abcd"变成"fgh"的步数, 求"abcde"到"fgh" "abcde"->"abcd"->"fgh"
                 int insert = db[i][j-1]+1; //增就等于另一个串的减 已知"abcde"变成"fg"的步数, 求"abcde"到"fgh" 
                 int change = db[i-1][j-1]; //替: 已知"abcd"变成“fg”, 求"abcde"到"fgh"  "abcde"->"fge"->"fgh"
                 if(word1[i-1]!=word2[j-1]) change += 1;
                 db[i][j] = min(insert, min(remove, change));
             }
         }
         return db[lenA][lenB];
    }
};
