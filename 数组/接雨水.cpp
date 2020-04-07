class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int left_max = 0, right_max = 0;
        int res = 0;
        while(left <= right){
            if(left_max < right_max){ //处理left
                res += max(0, left_max - height[left]);
                left_max = max(height[left], left_max);
                left++;
            }
            else{
                res += max(0, right_max - height[right]);
                right_max = max(height[right], right_max);
                right--;
            }
        }
        return res;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int left_max = 0, right_max = 0;
        int res = 0;
        while(left <= right){
            if(left_max < right_max){ //处理left
                res += max(0, left_max - height[left]);
                left_max = max(height[left], left_max);
                left++;
            }
            else{//处理right
                res += max(0, right_max - height[right]);
                right_max = max(height[right], right_max);
                right--;
            }
        }
        return res;
    }
};
