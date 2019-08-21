/*
     1
   / \
  2   2
 / \ / \
3  4 4  3
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
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
    bool isSymmetric(TreeNode* root) {
        return _isSymmetric(root, root);
    }

    bool _isSymmetric(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr) return true;
        if(root1 == nullptr || root2 == nullptr) return false;
        if(root1->val != root2->val) return false; //根节点
        return _isSymmetric(root1->left, root2->right) && _isSymmetric(root1->right, root2->left); //遍历左右节点
    }
 };
