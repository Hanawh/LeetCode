/*
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public: 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode *> tr;
        while(!tr.empty() || root != nullptr){
            if(root != nullptr){
                tr.push(root);
                root = root->left;
            }
            else{
                root = tr.top();
                tr.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};
