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
    bool res = true;
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        depth(root);
        return res;
    }

    int depth(TreeNode* root){
        if(root==nullptr) return 0;
        if(root->left==nullptr and root->right==nullptr) return 1; //叶子节点
        int leftdepth = depth(root->left);
        int rightdepth = depth(root->right);
        if(abs(leftdepth-rightdepth)>1) res = false;
        return max(leftdepth, rightdepth)+1;
    }
};
