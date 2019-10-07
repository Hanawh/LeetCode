/*
输入: 
nums = [1, 7, 3, 6, 5, 6]
输出: 3
解释: 
索引3 (nums[3] = 6) 的左侧数之和(1 + 7 + 3 = 11)，与右侧数之和(5 + 6 = 11)相等。
同时, 3 也是第一个符合要求的中心索引。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, left_sum = 0;
        for(auto &i : nums){
            sum += i;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(i == 0) left_sum = 0;
            else{
                left_sum += nums[i-1];
            }
            if(left_sum == (sum - left_sum - nums[i])) return i;
        }
        return -1;
    }
};
int main(){
    int a[6] = {1, 7, 3, 6, 5, 6};
    vector<int> v(a, *(&a + 1));
    cout << Solution().pivotIndex(v) << endl;
    return 0;
}
