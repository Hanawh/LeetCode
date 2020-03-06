class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> temp;
        //双指针法
        int l=1, r=2;
        while(l<r){
            int sum = (l+r)*(r-l+1)/2;
            if(sum == target){
                temp.clear();
                for(int i=l; i<=r; ++i){
                    temp.push_back(i);
                }
                res.push_back(temp);
                l++;
            }
            else if(sum < target){
                r++;
            }
            else l++;
        }
        return res;
    }
};
