/*
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

对于元素i要么是以第i-1个元素结尾且和最大的连续子数组加上这个元素，要么是只包含第i个元素，即sum[i]
max(sum[i-1] + a[i], a[i])
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public: 
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxsub = 0;
        for(auto i = 0; i < nums.size(); ++i){
            if(maxsub > 0) maxsub += nums[i];
            else{
                maxsub = nums[i];
            }
            if(maxsub > sum) sum = maxsub;
        }
        return sum;
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(nums) << endl;
}
