class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; //维护递增栈
        int len = heights.size();
        if(len == 0) return 0;
        if(len == 1) return heights[0];
        int res = 0;
        st.push(0); //第一个元素index入栈
        for(int i=1; i<len; ++i){
            while(!st.empty() and heights[st.top()]>heights[i]){
                //此时出栈 
                int ind = st.top();
                st.pop();
                while(!st.empty() and heights[st.top()] == heights[ind]) st.pop();
                if(!st.empty()){
                    int right = st.top();
                    int distance = i-right-1;
                    res = max(res, heights[ind]*distance);
                }
                else{
                    res = max(res, heights[ind]*i);
                }
            }
            st.push(i);
        }
        //栈还会有剩余
        while (!st.empty())
        {
            int ind = st.top();
            st.pop();
            while(!st.empty() and heights[st.top()] == heights[ind]) st.pop();
            if(!st.empty()){
                    int right = st.top();
                    int distance = len-right-1;
                    res = max(res, heights[ind]*distance);
            }
            else{
                    res = max(res, heights[ind]*len);
                }
        }
        
        return res;
    }
};
