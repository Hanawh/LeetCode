class Solution {
public:
    int waysToChange(int n) {
        int value[5] = {0, 1, 5, 10, 25};
        vector<int> table(n+1);
        //f(i,v) = f(i-1,v) + f(i,v-c_i)
        table[0] = 1; //f(i-1,0)=1
        for(int i=1; i<=4; ++i){ //前i种面值
            for(int j=value[i]; j<=n; ++j){
                table[j] = (table[j] + table[j-value[i]]) % 1000000007;
            }
        }
        return table[n];
    }
};
