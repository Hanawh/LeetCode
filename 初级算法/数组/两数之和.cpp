/*给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
 */
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> temp;
        for(int i=0; i<nums.size(); ++i)
        {
            if(temp.count(target-nums[i])) 
            return {temp[target-nums[i]], i};
            temp[nums[i]]=i; 
        }
        return {};
    }
};
int main()
{
    int nums[]={2, 7, 11, 15}, target=9;
    vector<int> vec_nums(nums, nums + sizeof(nums) / sizeof(int));
    vector<int> result=Solution().twoSum(vec_nums, target);
    for(auto i:result) cout<<i<<" ";
    return 0;
}
