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

    TreeNode* buildTree(vector<string> &tree, size_t size, int index, const string& invalid){
        TreeNode *root;
        if(index < size){
            if(tree[index] == invalid){
                root = nullptr;
            }
            else{
                root = new TreeNode(stoi(tree[index]));
                root->left = buildTree(tree, size, ++index, invalid);
		        root->right = buildTree(tree, size, ++index, invalid);
            }
        }
        return root;
    }
};

int main(){
    vector<string> tree;
    string s;
    while (cin >> s && s != "end") //end表示输入完毕 null表示空 eg:3 9 20 null null 15 7 end
    {
        tree.push_back(s); //创建树序列
    }
    TreeNode *binarytree = Solution().buildTree(tree, tree.size(), 0, "null");
    cout << Solution().maxDepth(binarytree) << endl;
    return 0;
}
