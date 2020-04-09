class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        depthSearch("(", 1, 1, n);
        return res;
    }

    void depthSearch(string s, int n, int depth, int nums){
        if(depth<0) return;
        if(n==nums){ //就在后面补depth个右括号
            while(depth--) s+=")";
            res.push_back(s);
        }
        else{
            depthSearch(s+"(", n+1, depth+1, nums);
            depthSearch(s+")", n, depth-1, nums);
        }
    }
};
