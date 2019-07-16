/*输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    void rotation(vector<int>& nums, int start, int end)
    {
         while(start <= end){
             int temp;
             temp = nums[start];
             nums[start] = nums[end];
             nums[end] = temp;
             start++;
             end--;
         }
    }
    void rotate(vector<int>& nums, int k) {
        int len;
        len = nums.size();
        if(k > len) k = k % len;
        rotation(nums,len-k,len-1);
        rotation(nums,0,len - k - 1);
        rotation(nums,0,len - 1);
    }
};
int main()
{
    int nums[]={1, 2, 3, 4, 5, 6, 7}, k=3;
    vector<int> vec_nums(nums, nums + sizeof(nums) / sizeof(int));
    Solution().rotate(vec_nums, k);
    for(auto i:vec_nums) cout<<i;
    return 0;
}
