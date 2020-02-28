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
    bool isSymmetric(TreeNode* root) {
        return _isSymmetric(root, root);
    }

    bool _isSymmetric(TreeNode* rootA, TreeNode* rootB){
        if(rootA==nullptr and rootB==nullptr) return true;
        if(rootA==nullptr || rootB==nullptr) return false;
        if(rootA->val != rootB->val) return false;
        return _isSymmetric(rootA->left, rootB->right) && _isSymmetric(rootA->right, rootB->left);
    }
};
