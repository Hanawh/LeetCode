class Solution {
public:
    vector<vector<int> > levelOrder(Node* root) {
        if(root==nullptr) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int> > res;
        vector<int> tmp;
        while(!q.empty()){
            tmp.clear();
            int len = q.size();
            //cout<<len<<endl;
            for(int i=0; i<len; ++i){
                Node* n = q.front();
                q.pop();
                tmp.push_back(n->val);
                for(int j=0; j<n->children.size(); ++j){
                    q.push(n->children[j]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
