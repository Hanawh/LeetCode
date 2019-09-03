/*
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
输入: [3,0,1]
输出: 2

输入: [9,6,4,2,3,5,7,0,1]
输出: 8

你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
*/
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto n = nums.size();
        auto sum = n*(n+1)/2;
        return sum - accumulate(nums.begin(), nums.end(), 0); //accumulate包含在<numeric>中
    }
};

int main(){
    vector<int> nums = {3,0,1};
    cout << Solution().missingNumber(nums);
    return 0;
}
