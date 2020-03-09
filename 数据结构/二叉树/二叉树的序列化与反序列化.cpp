/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "#,";
        string res = to_string(root->val)+",";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.size();
        queue<string> q;
        while (data.size())
        {
            int pos = data.find_first_of(',');
            if(pos!=string::npos){
                q.push(data.substr(0, pos));
                data = data.substr(pos+1);
            }
        }
        
        TreeNode* res = _deserialize(q);
        return res;
    }

     TreeNode* _deserialize(queue<string>& q) {
        if(q.front() == "#"){
            q.pop();
            return nullptr;
        }
        else{
            TreeNode* node = new TreeNode(stoi(q.front()));
            q.pop();
            node->left = _deserialize(q);
            node->right = _deserialize(q);
            return node;
        }
    }
};
