class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far_dis;
        int len = nums.size();
        if(len==1) return true;
        for(int i=0; i<len-1; ++i){
            if(i==0) far_dis = i+nums[i];
            if(i<=far_dis) far_dis = max(far_dis, i+nums[i]);
            if(far_dis>=len-1) return true;
        }
        return false;
    }
};
