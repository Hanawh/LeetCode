/*输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
可以不考虑输出结果的顺序。
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution
{
public:
   vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> record;
        vector<int> result;
        for (auto& num : nums1) ++record[num];
        for (auto& num : nums2)
        {
            if (record[num] > 0)
            {
                result.push_back(num);
                --record[num];
            }
        }
        return result;
    }
};
int main()
{
    int nums1[]={4, 9, 5}, nums2[]={9,4,9,8,4};
    vector<int> vec_nums1(nums1, nums1 + sizeof(nums1) / sizeof(int));
    vector<int> vec_nums2(nums2, nums2 + sizeof(nums2) / sizeof(int));
    vector<int> result=Solution().intersect(vec_nums1, vec_nums2);
    for(auto i:result) cout<<i;
    return 0;
}
