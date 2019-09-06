/*
如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。

输入: [1,2,3,4,5]
输出: true
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int fir = INT32_MAX, sec = INT32_MAX;
        for(auto& i:nums){
            if(i < fir){
                fir = i;
            }
            else if(i > fir && i < sec){
                sec = i;
            }
            else if(i > sec){
                return true;
            }
        }
        return false;
    }
};

int main(){
    vector<int> nums{5, 6, 2, 3, 4};
    cout << boolalpha << Solution().increasingTriplet(nums) << endl;
    return 0;
}
