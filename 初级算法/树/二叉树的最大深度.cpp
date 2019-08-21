/*
   3
   / \
  9  20
    /  \
   15   7

给定二叉树 [3,9,20,null,null,15,7]，返回它的最大深度 3 
*/
#include<iostream>
#include<algorithm>
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        else{
            int leftdepth = maxDepth(root->left);
            int rightdepth = maxDepth(root->right);
            return max(leftdepth, rightdepth) + 1;
        }
    }
};

