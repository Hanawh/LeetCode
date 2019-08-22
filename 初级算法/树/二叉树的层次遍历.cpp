/*
 给定二叉树: [3,9,20,null,null,15,7],
   3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]
*/
#include<iostream>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<TreeNode *> que;
        que.push(root);
        TreeNode *temp;
        vector<int> temp_result;
        while(!que.empty()){
            int len = que.size();
            for (int i = 0; i < len; ++i){ //此处len不能直接用que.size() 
                temp = que.front();
                temp_result.push_back(temp->val);
                que.pop();
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            } 
            result.push_back(temp_result);
            temp_result.clear();
        }
        return result;
    }
};
