class Solution {
public:
    //找到最靠近 x（两数之差最小）的 k 个数，如果有两个数与 x 的差值一样，优先选择数值较小的那个数。
    //双指针法
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
        int left = 0, right = len - 1;
        while(right - left + 1 > k){
            int a = abs(x - arr[left]);
            int b = abs(arr[right] - x);
            if(a <= b) right--;
            else left++;
        }
        vector<int> res;
        res.assign(arr.begin() + left, arr.begin() + right + 1);
        return res;
    }
};
