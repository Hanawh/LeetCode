/*
输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。
*/
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0; 
        int max = 0;
        int len = 0;
        for(int i = 0; i < size; ++i){
            if(nums[i] == 1) len++;//Consecutive one
            else{
                if(len > max) max = len;
                len = 0;
            }
        }
        if(len > max) max = len;
        return max;
    }
};
int main(){
    vector<int> nums{1,0,1,1,0,1};
    cout << Solution().findMaxConsecutiveOnes(nums);
    return 0;
}
