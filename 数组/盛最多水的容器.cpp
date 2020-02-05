class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i = 0;
        int j = len-1;
        int maxval = 0;
        while(i<j){
            int tmp = min(height[i],height[j])*(j-i);
            maxval = max(tmp, maxval);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxval;
    }
};
