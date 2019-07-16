/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
输入: [2,2,1]
输出: 1

0的异或性质
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        for(auto i:nums)
        {
            a ^= i;
        }
        return a;
    }
};
int main()
{
    int nums[]={2, 2, 1};
    vector<int> vec_nums(nums, nums + sizeof(nums) / sizeof(int));
    int result=Solution().singleNumber(vec_nums);
    cout<<result;
    return 0;
}
