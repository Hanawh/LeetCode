#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int cur=0; 
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i]==nums[cur]) continue;
            else nums[++cur]=nums[i];
        }
        return cur+1;
    }
};
int main()
{
    int nums[]={0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> vec_nums(nums, nums + sizeof(nums) / sizeof(int));
    int len = Solution().removeDuplicates(vec_nums);
    for (int i = 0; i < len; i++) 
    {
        cout<<vec_nums[i];
    }
    return 0;
}
