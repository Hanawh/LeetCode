class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr and t == nullptr) return true;
        if(s == nullptr or t == nullptr) return false;
        if(s->val == t->val and same(s, t)){ //仍需判断是否相同
            return true;
        }
        return isSubtree(s->left, t) or isSubtree(s->right, t);
    }

    bool same(TreeNode* s, TreeNode* t){
        if(s == nullptr and t == nullptr) return true;
        if(s == nullptr or t == nullptr or s->val != t->val) return false;
        return same(s->left, t->left) and same(s->right, t->right);

    }
};
