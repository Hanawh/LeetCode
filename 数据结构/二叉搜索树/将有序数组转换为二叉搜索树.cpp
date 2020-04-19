/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
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
