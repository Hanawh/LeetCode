/*输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int>& nums) {
        int cur=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]!=0) nums[cur++]=nums[i];
        }
        for(int i=cur;i<nums.size();++i)
        {
            nums[i]=0;
        }
    }
};
int main()
{
    int nums[]={0, 1, 0, 3, 12};
    vector<int> vec_nums(nums, nums + sizeof(nums) / sizeof(int));
    Solution().moveZeroes(vec_nums);
    for(auto i:vec_nums) cout<<i<<" ";
    return 0;
}
