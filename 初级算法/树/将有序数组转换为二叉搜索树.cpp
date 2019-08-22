/*
 给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public: 
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size()-1);
    }

    TreeNode* _sortedArrayToBST(vector<int>& nums, int start, int end){
        if(start > end) return nullptr;
        int mid = (end + start)/2;
        TreeNode* midNode = new TreeNode(nums[mid]);
        midNode->left = _sortedArrayToBST(nums, start, mid-1);
        midNode->right = _sortedArrayToBST(nums, mid+1, end);
        return midNode;
    }
};
