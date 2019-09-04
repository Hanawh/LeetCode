/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int left, right;
        for(auto i = 0; i < len; ++i){
            if(nums[i] > 0) break; //只需要遍历负数
            if(i > 0 && nums[i - 1] == nums[i]) continue; //去掉重复的
            
            left = i + 1;
            right = len - 1;

            while(left < right){
                if(nums[left] + nums[right] == -nums[i]){
                    result.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    while(left < right && nums[left] == nums[left-1]) ++left;
                    --right;
                }
                else if(nums[left] + nums[right] < -nums[i]) ++left;
                else  --right;
            }
        }
        return result;
    }
};

int main(){
    vector<int> s = {-1, 0, 1, 2, -1, -4};
    for (auto& i : Solution().threeSum(s)){
        for (auto& j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
