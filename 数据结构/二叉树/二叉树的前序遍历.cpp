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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res; 
    }
    
    void preorder(TreeNode* root, vector<int>& res){
        if(root){
            res.push_back(root->val);
            preorder(root->left, res);
            preorder(root->right, res);
        }
        else return;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur or !st.empty()){
            while(cur) {
                st.push(cur);
                res.push_back(cur->val);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
        return res; 
    }
};
