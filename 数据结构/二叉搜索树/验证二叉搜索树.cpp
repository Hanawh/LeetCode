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
    bool isValidBST(TreeNode* root) {
        return _isvalid(root, nullptr, nullptr);
    }

    bool _isvalid(TreeNode* root, TreeNode* lower, TreeNode* upper){
        if(root == nullptr) return true;
        if(lower and lower->val >= root->val) return false;
        if(upper and upper->val <= root->val) return false;
        return _isvalid(root->left, lower, root) and _isvalid(root->right, root, upper); 
    }
};
