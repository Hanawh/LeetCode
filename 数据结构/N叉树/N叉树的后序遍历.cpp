class Solution {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {
        _postorder(root);
        return res;
    }

    void _postorder(Node* root){
        if(root==nullptr) return;
        int len = root->children.size();
        for(int i=0; i<len; ++i){
            _postorder(root->children[i]);
        }
        res.push_back(root->val);
    }
};
