class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> map;
        for(int i = 0; i < list1.size(); ++i){
            map[list1[i]] = i;
        } 
        int minimum = 10000;
        for(int i = 0; i < list2.size(); ++i){
            if(map.count(list2[i])){
                int sum = map[list2[i]] + i;
                if(sum < minimum) {
                    res.clear();
                    res.push_back(list2[i]);
                    minimum = sum;
                }
                else if(sum == minimum) res.push_back(list2[i]);
            }
        } 
        return res;
    }
};
