class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            auto lower = s.lower_bound(nums[i]); //指向大于等于nums[i]的最小元素
            auto upper = s.upper_bound(nums[i]); //指向小于等于nums[i]最大元素的后一个值
            if ((lower != s.end() && *lower <= nums[i] + t) || (upper != s.begin() && nums[i] <= *--upper + t)) return true; // upper 为 s.begin() 时说明查找结果为空
            s.insert(nums[i]);
            if (s.size() > k) s.erase(nums[i - k]);
        }
        return false;
    }
};
