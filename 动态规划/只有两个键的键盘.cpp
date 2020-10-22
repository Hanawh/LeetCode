class Solution {
public:
    int minSteps(int n) {
        vector<int> tb(n+1,INT_MAX); //最小操作次数
        tb[1]=0;
        for(int i=2; i<=n; ++i){
            //每一个i都可以由最初的A复制一次， 粘贴i-1次得到
            tb[i] = i;
            for(int j=1; j<i; j++){
               //如果i能除尽j 说明i可以通过多次粘贴j得到
               if(i%j == 0){
                   tb[i] = min(tb[i], tb[j] + 1 + (i-j)/j);
               }

            }
        }
        return tb[n];
    }
};
