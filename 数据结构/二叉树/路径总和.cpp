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
    bool res=false;
    bool hasPathSum(TreeNode* root, int sum) {
        path(root, sum);
        return res;
    }
    
    void path(TreeNode* root, int sum){
        if(root==nullptr) return;
        if(!root->left and !root->right){ //根节点
            if(sum==root->val){
                res = true;
            }
        }
        else{
            hasPathSum(root->left, sum-root->val);
            hasPathSum(root->right, sum-root->val);
        }
    }
};
