/*
给定 n = 5，并且 version = 4 是第一个错误的版本。

调用 isBadVersion(3) -> false
调用 isBadVersion(5) -> true
调用 isBadVersion(4) -> true

所以，4 是第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。
实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。
*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
class Solution{
public: 
    int firstBadVersion(int n) {
        long head = 0, last = n;
        while (head < last){
            long mid = (head + last) / 2;
            if (isBadVersion(mid)) last = mid;
            else head = mid + 1;
        }
        return head;
    }
};
