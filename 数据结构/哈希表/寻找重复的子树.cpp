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
     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> hash;
        vector<TreeNode*> res;
        if(root == nullptr) return res;
        dfs(root, res, hash);
        return res;
    }

    string dfs(TreeNode* root, vector<TreeNode*> &res, unordered_map<string, int> &hash){
        if(root==nullptr) return "";
        string str = to_string(root->val)+"("+dfs(root->left,res,hash)+",)"+dfs(root->right,res,hash);
        if(hash[str]==1) res.push_back(root); //否则会重复添加
        hash[str]++;
        return str;
    }
};
