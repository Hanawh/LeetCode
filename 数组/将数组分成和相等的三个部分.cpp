class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for(auto &i : A){
            sum += i;
        }
        if(sum % 3!=0) return false;
        
        int each_sum = sum/3;

        sum = 0;
        int count = 0; //等于目标和的个数
        for(int i = 0; i < A.size(); ++i){
            sum += A[i];
            if(sum == each_sum){
                count ++;
                sum = 0;
            }
            if(count == 3) return true;
        }
        return false;
    }
};
