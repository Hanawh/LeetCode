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
    unordered_map<int, int> m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); ++i){
            m[inorder[i]]=i;
        }

        return build(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder);
    }

    TreeNode* build(int pre_ind1, int pre_ind2, int in_ind1, int in_ind2, vector<int>& preorder, vector<int>& inorder){
        if(pre_ind1>pre_ind2 or in_ind1>in_ind2) return nullptr;
        int pos = m[preorder[pre_ind1]];
        int len = pos-in_ind1;
        TreeNode* root = new TreeNode(preorder[pre_ind1]);
        root->left=build(pre_ind1+1, pre_ind1+len, in_ind1, pos-1, preorder, inorder);
        root->right=build(pre_ind1+len+1, pre_ind2, pos+1, in_ind2, preorder, inorder);
        return root;
    }
};
