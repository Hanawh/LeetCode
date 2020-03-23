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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr; //空节点
        if(root->val < key) root->right = deleteNode(root->right, key);
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else{ //等于要删除的节点时有三种情况
            TreeNode* temp;
            if(root->left==nullptr and root->right==nullptr) root=nullptr; //叶子节点
            else if(root->left){ //只有左孩子,找前继,左孩子的右孩子
                temp = root->left;
                while(temp->right){
                    temp = temp->right;
                }
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
            else{//只有右孩子,找后继,右孩子的左孩子
                temp = root->right;
                while(temp->left){
                    temp = temp->left;
                }
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};
