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
    string tree2str(TreeNode* t) {
        if(t==nullptr) return "";
        string str = dfs(t);
        return str;
    }

    string dfs(TreeNode* t){
        if(t==nullptr) return "";
        if(t->left==nullptr and t->right==nullptr) return to_string(t->val);
        if(t->right==nullptr) return to_string(t->val)+"("+dfs(t->left)+")";
        return to_string(t->val)+"("+dfs(t->left)+")"+"("+dfs(t->right)+")";
    }
};
