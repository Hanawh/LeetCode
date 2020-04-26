class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > permute(vector<int>& nums) {
        //依次交换第一个像素和之后的
        _permute(nums, 0);
        return res;
    }

    void _permute(vector<int> nums, int start){
        int len = nums.size();
        //交换start和之后每一位
        if(start == len-1){
            res.push_back(nums);
            return;
        }
        for(int i=start; i<len; ++i){
            swap(nums[start], nums[i]);
            _permute(nums, start+1);
            swap(nums[start], nums[i]);//交换回来
        }
    }

    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
};
