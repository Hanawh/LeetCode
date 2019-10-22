
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if(rowIndex < 0) return res;
        res.assign(rowIndex + 1, 0);
        res[0] = 1;
        for(int i = 1; i <= rowIndex; ++i){//行数索引
            for(int j = i; j >= 1; --j){//第i行有i+1个值 应该从后向前加
                res[j] = res[j] + res[j-1];
            }
        } 
        return res;
    }
};
