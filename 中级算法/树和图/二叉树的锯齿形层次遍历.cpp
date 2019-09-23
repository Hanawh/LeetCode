/*
  3
   / \
  9  20
    /  \
   15   7
输出：
[
  [3],
  [20,9],
  [15,7]
]
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public: 
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 1;//标志着入队顺序
        vector<int> temp_result;
        while(!q.empty()){
            TreeNode *temp;
            int len = q.size();
            for(int i = 0; i < len; ++i){
                temp = q.front();
                temp_result.push_back(temp->val);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if (flag % 2 == 0){
                reverse(temp_result.begin(), temp_result.end()); //#include<algorithm> 
            }
            flag++;
            result.push_back(temp_result);
            temp_result.clear(); //注意清空变量
        }
        return result;
    }
};
