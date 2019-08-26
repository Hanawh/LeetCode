/*
输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public: 
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int pre = 0, cur = 0;
        for(auto &i : nums){
            int temp = cur;
            cur = max(pre + i, cur);
            pre = temp;
        }
        return cur;
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 1};
    cout << Solution().rob(nums) << endl;
}
