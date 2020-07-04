class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int len = s.size();
        int res = 0;
        int maxval = 0;
        for(int i=0; i<len; ++i){
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(!st.empty()){
                    res = i - st.top();
                    maxval = max(maxval, res); 
                }
                else{
                    st.push(i);
                }
            }
        }
        return maxval;
    }
};
