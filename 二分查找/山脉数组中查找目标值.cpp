/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int left = 0, right = len - 1;
        //二分法先找峰值
        while(left < right){
            int mid = left + (right - left)/2;
            if(mountainArr.get(mid) > mountainArr.get(mid+1)){
                right = mid;
            }
            else{ //mountainArr.get(mid) <= mountainArr.get(mid+1)
                left = mid + 1;
            }
        }
        //此时left或right就是峰值所在位置
        //分别对两边进行二分查找target
        int res = BinarySearch(mountainArr, 0, left, target, 0); //递增序列
        cout << res<< endl;
        if(res != -1) return res;
        return BinarySearch(mountainArr, left+1, len-1, target, 1); //递减序列
    }

    int BinarySearch(MountainArray &mountainArr, int left, int right, int target, int reverse){
        if(left == right) return (mountainArr.get(left) == target? left : -1); 
        if(reverse == 1) target *= -1;
        while(left < right){
            int mid = left + (right - left)/2;
            int cur = mountainArr.get(mid);
            if(reverse == 1) cur *= -1;
            if(cur < target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        int cur = mountainArr.get(left);
        if(reverse == 1) cur *= -1;
        if(cur == target) return left;
        return -1;
    }
};
