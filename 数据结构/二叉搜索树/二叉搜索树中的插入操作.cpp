class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        TreeNode* cur = root;
        while(cur!=nullptr){
            if(cur->val < val) {
                if(cur->right) cur=cur->right;
                else {
                    cur->right = node;
                    return root;
                }
            }
                
            else {
                if(cur->left) cur=cur->left;
                else {
                    cur->left = node;
                    return root;
                }
            }
        }
        return root;
    }
};
