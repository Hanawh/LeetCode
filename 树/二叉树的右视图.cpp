class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; ++i){
                TreeNode* top = q.front();
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                if(i==len-1) res.push_back(top->val);
            }
        }
        return res;
    }
};
