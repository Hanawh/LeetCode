/*
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public: 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        m--; n--;
        while (m >= 0 && n >= 0){
            if(nums1[m] > nums2[n]){
                nums1[k--] = nums1[m--];
            }
            else{
                nums1[k--] = nums2[n--];
            }
        }
        while (n >= 0){
            nums1[k--] = nums2[n--];
        }
    }
};

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    Solution().merge(nums1, m, nums2, n);
    for (auto& num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
