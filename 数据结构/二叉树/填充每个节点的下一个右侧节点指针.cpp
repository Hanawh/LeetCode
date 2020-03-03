/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            Node* pre = q.front();
            q.pop();
            if(pre->left) q.push(pre->left);
            if(pre->right) q.push(pre->right);
            for(int i=0; i<len-1; ++i){
                pre->next = q.front();
                pre = q.front();
                if(pre->left) q.push(pre->left);
                if(pre->right) q.push(pre->right);
                q.pop();
            }
        }
        return root;

    }
};
