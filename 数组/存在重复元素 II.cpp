class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()<=1) return false;
        vector<vector<int> > tmp(nums.size(),vector<int>(2));
        for(int i = 0; i < nums.size(); ++i){
            tmp[i][0] = nums[i];
            tmp[i][1] = i;
        }

        sort(tmp.begin(),tmp.end(),cmp);
        
        for(int i = 0; i < nums.size()-1; ++i){
            if(tmp[i][0] == tmp[i+1][0]){
                if(abs(tmp[i][1] - tmp[i+1][1])<=k) return true;
            }
        }
        return false;
    }

    static bool cmp(vector<int>& tmp1, vector<int>& tmp2){
        if(tmp1[0]<tmp2[0]) return true;
        else return false;
    }
};//28ms 15.1MB
