class Solution {
public:
    bool divisorGame(int N) {
        if(N==1) return 0;
        if(N==2) return 1;
        vector<int> table(N+1);
        table[2] = 1;
        if(N < 3) return table[N]; 
        for(int i = 3; i <= N; ++i){
            for(int j = 1; j < i; ++j) // 寻找满足N % x == 0的x
            {
                if(i%j == 0 and table[i-j]==0){ //默认是0，所以只需要找前者为0的情况
                    table[i] = 1;
                }
            }
        }
        return table[N];
    }
};
