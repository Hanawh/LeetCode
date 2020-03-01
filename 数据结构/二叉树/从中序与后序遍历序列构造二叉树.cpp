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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //因为元素不同，利用哈希映射存储中序遍历位置
        for(int i = 0; i < inorder.size(); ++i){
            m[inorder[i]] = i;
        }
        return build(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder);
    }

    TreeNode* build(int ind_in1, int ind_in2, int ind_post1, int ind_post2, vector<int>& inorder, vector<int>& postorder){
        if(ind_in1>ind_in2 or ind_post1>ind_post2) return nullptr;
        //找到根节点在中序数组中的位置
        int pos = m[postorder[ind_post2]];
        int len = pos-ind_in1;
        //建立根节点
        TreeNode* root = new TreeNode(postorder[ind_post2]);
        root->left = build(ind_in1, pos-1, ind_post1, ind_post1+len-1, inorder, postorder);
        root->right = build(pos+1, ind_in2, ind_post1+len, ind_post2-1, inorder, postorder);
        return root;
    }
};
