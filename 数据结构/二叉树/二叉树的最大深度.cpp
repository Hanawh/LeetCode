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
    int res;
    int maxDepth(TreeNode* root)
    {
        depth(root, 1);
        return res;
    }
    
    void depth(TreeNode* root, int d)
    {
        if(root==nullptr) return;
        if(root->left or root->right){
            depth(root->left, d+1);
            depth(root->right, d+1);
        }
        else res=max(d, res);
    }
        
};
