class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len=nums.size();
        int r=0, l=0; //r在框外 l在框内
        int sum=0;
        int minlen=len+1;
        while(l<len){
            if(r<len and sum<s){
                sum += nums[r++];
            }
            else{
                sum -= nums[l++];
            }
            if(sum >= s) minlen = min(minlen, r-l);
        }
        if(minlen==len+1) return 0;
        return minlen;
    }
};
