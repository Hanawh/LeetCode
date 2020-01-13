class NumArray {
public:
    NumArray(vector<int>& nums) {
        acc_sum.resize(nums.size());
        int temp = 0;
        for(int i=0; i<nums.size(); ++i){
            temp += nums[i];
            acc_sum[i] = temp;
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0){
            return acc_sum[j];
        }
        return acc_sum[j]-acc_sum[i-1];
    }

private:
    vector<int> acc_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
