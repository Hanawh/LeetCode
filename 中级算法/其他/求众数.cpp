/*
输入: [2,2,1,1,1,2,2]
输出: 2
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public: //若数组中的数据经过排序后， 那么众数就是数组中位于n/2处的元素。
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        return nums[size/2];
    }
};

int main(){
    vector<int> numbers = {2, 7, 11, 15, 2, 2, 2};
    cout << Solution().majorityElement(numbers);
    return 0;
}
