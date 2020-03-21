class Solution {
public:
    struct HashPair {
        size_t operator()(const pair<int, int> &key) const noexcept
	    {
		    return size_t(key.first)*100000007 + key.second;
	    }
    };
    
    bool canMeasureWater(int x, int y, int z) {
        queue<pair<int, int> >  q;
        unordered_set<pair<int, int>, HashPair> s;
        //初始状态0,0 目标状态x+y==z
        q.push(make_pair(0,0));
        s.insert(make_pair(0,0));
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            if (temp.first + temp.second == z or temp.first == z or temp.second == z) return true;
            for(int i = 0; i < 6; i++) {
                auto next = generate(i, temp, x, y);
                if(s.find(next) != s.end()) {
                    continue;
                }
                s.insert(next);
                q.push(next);
            }
        }
        return false;
    }

    pair<int, int> generate(int i, pair<int, int> &state, int x, int y){
        switch (i)
        {
            case 0 : return make_pair(x, state.second);
            case 1 : return make_pair(state.first, y);
            case 2 : return make_pair(0, state.second);
            case 3 : return make_pair(state.first, 0);
            case 4 :{
                //x倒入y中
                if(state.first + state.second < y){
                     return make_pair(0, state.first + state.second);
                }
                else{
                    return make_pair(state.first + state.second - y, y);
                }
            }
            case 5 : {
                //y倒入x中
                if(state.first + state.second < x){
                     return make_pair(state.first + state.second, 0);
                }
                else{
                    return make_pair(x, state.first + state.second - x);
                }

            }
        }
        return make_pair(0,0);
    }
};
