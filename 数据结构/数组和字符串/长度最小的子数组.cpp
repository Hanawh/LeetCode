class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if(len==0) return 0;
        vector<int> t(len+1);
        for(int i=1; i <= len; ++i){
            t[i] = nums[i-1] + t[i-1];
        }

        int res = INT32_MAX;
        for(int i=0; i <= len-1; ++i){
            int left = i+1, right = len;
            int target = s + t[i];
            while(left < right){
                int mid = left + (right - left)/2;
                if(t[mid] < target) left = mid + 1;
                else right = mid;
            }
            if(t[left] >= target) res = min(res, left-i);
        }
        if(res == INT32_MAX) return 0;
        return res;
    }
}; //O(nlogn) 二分法

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
}; //双指针
