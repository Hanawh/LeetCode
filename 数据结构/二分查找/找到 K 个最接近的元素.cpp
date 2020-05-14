class Solution {
public:
    //找到最靠近 x（两数之差最小）的 k 个数，如果有两个数与 x 的差值一样，优先选择数值较小的那个数。
    //双指针法
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
        int left = 0, right = len - 1;
        while(right - left + 1 > k){
            int a = x - arr[left];
            int b = arr[right] - x;
            if(a <= b) right--;
            else left++;
        }
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};

class Solution {
public:
    //找到最靠近 x（两数之差最小）的 k 个数，如果有两个数与 x 的差值一样，优先选择数值较小的那个数。
    //双指针法
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
        int left = 0, right = len - k;
        while(left < right){
            int mid = left + (right - left) / 2;
            //此时窗口为k+1大小的 [mid, mid + k]
            //x不在区间内
            //x在区间左边
            if(arr[mid] > x){
                right = mid;
            }
            else if(arr[mid+k] < x){
                left = mid + 1;
            }
            else{ //x in [mid, mid+k]
                if(x - arr[mid] <= arr[mid+k] - x){
                    right = mid;
                }
                else left = mid + 1;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
