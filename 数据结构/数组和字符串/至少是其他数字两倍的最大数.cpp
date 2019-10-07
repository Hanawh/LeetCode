/*
输入: nums = [3, 6, 1, 0]
输出: 1
解释: 6是最大的整数, 对于数组中的其他整数,
6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int max = nums[0], ind = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > max) {
                max = nums[i];
                ind = i;
            }
        }

        for(int i = 0; i < nums.size(); ++i){
            if(i == ind) continue;
            else{
                if(nums[i] * 2 > max) return -1;
            }
        }
        return ind;
    }
};
int main(){
    int a[4] = {3, 6, 1, 0};
    vector<int> v(a, *(&a + 1));
    cout << Solution().dominantIndex(v) << endl;
    return 0;
}
