/*输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0) return false;
        sort(nums.begin(),nums.end());
        for(int i=1; i<nums.size(); ++i)
        {
            if (nums[i]==nums[i-1]) return true;
        }
        return false;
    }
};
int main()
{
    int nums[]={1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    vector<int> vec_nums(nums, nums + sizeof(nums) / sizeof(int));
    bool result=Solution().containsDuplicate(vec_nums);
    cout<<boolalpha<<result; //注意要用boolalpha来将1转换为True
    return 0;
}
