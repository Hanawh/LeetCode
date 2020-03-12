//方法一
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        int tmp = q.front();
        q.pop();
        return tmp;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }

    void inorder(TreeNode* root){
        if(root == nullptr) return;
        if(root->left) inorder(root->left);
        q.push(root->val);
        if(root->right) inorder(root->right);
        return;
    }
private:
    queue<int> q;
};

//方法二
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        step(root);
    }
    
    /** @return the next smallest number */
    int next() {
        int res;
        if(!q.empty()){
            TreeNode* tmp = q.top();
            q.pop();
            res = tmp->val;
            step(tmp->right);
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }

    void step(TreeNode* root){
        while(root){
            q.push(root);
            root = root->left;
        }
    }
private:
    stack<TreeNode*> q;
};
