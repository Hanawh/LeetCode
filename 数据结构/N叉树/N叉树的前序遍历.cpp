class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        _preorder(root);
        return res;
    }

    void _preorder(Node* root){
        if(root==nullptr) return;
        res.push_back(root->val);
        int len = root->children.size();
        for(int i=0; i<len; ++i){
            _preorder(root->children[i]);
        }
    }
};
