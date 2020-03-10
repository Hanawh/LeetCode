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
    int d = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        depth(root);
        return d;

    }

    int depth(TreeNode* root){
        if(root==nullptr) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        d = max(d, L+R);
        return max(L,R)+1; //从低之上第几个
    }
};
