/*
  输入:
    2
   / \
  1   3
输出: true

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public: 
    bool isValidBST(TreeNode* root) {
        return _isVaildBST(root, nullptr, nullptr); //应该判断的是系统最大值和最小值
    }

    bool _isVaildBST(TreeNode* root, TreeNode* left, TreeNode* right)
    {
        if (root == nullptr) return true;
        if (left and left->val >= root->val) return false;
        if (right and right->val <= root->val) return false;
        return _isVaildBST(root->left, left, root) and _isVaildBST(root->right, root, right);
    }
};
