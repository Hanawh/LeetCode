/*
输入: [[1],[2],[3],[]]
输出: true
解释:  
我们从 0 号房间开始，拿到钥匙 1。
之后我们去 1 号房间，拿到钥匙 2。
然后我们去 2 号房间，拿到钥匙 3。
最后我们去了 3 号房间。
由于我们能够进入每个房间，我们返回 true。
*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int> >& rooms) {
        int nums = rooms.size();
        stack<int> st;
        set<int> s;
        s.insert(0);
        
        //将房间0的钥匙入栈
        for(int i = 0; i < rooms[0].size(); ++i){
            if(rooms[0][i]) st.push(rooms[0][i]);
        }

        while(!st.empty()){
            int tmp = st.top();
            st.pop();

            //扩展节点
            if(!s.count(tmp)){
                s.insert(tmp);
            }
            for(int i = 0; i < rooms[tmp].size(); ++i){
                if(!s.count(rooms[tmp][i])) st.push(rooms[tmp][i]);
            }
        }
        for(int i = 0; i < nums; ++i){
            if(!s.count(i)) return false;
        }
        return true;

    }
};//8ms 11.3MB
