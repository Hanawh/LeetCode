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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    
    void postorder(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        unordered_set<TreeNode*> hash;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* tmp = st.top();
            st.pop();
            if(hash.count(tmp)){//已经访问过一次
                res.push_back(tmp->val);
            }
            else if(tmp->left==nullptr and tmp->right==nullptr) res.push_back(tmp->val);
            else{
                st.push(tmp);
                if(tmp->right) st.push(tmp->right);
                if(tmp->left) st.push(tmp->left);
                hash.insert(tmp);
            }
        }
        return res;
    }
};
