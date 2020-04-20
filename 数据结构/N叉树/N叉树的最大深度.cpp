class Solution {
public:
    int maxDepth(Node* root) {
        if(root==nullptr) return 0;
        if(root->children.size()==0) return 1;
        int depth = 0;
        for(int i=0; i<root->children.size(); ++i){
            depth = max(depth, maxDepth(root->children[i]));
        }
        return depth+1;
    }
};
