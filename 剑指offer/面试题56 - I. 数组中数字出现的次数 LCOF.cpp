class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int res = 0;
		for (int n : nums)
			res ^= n;
		int div = 1;
		while ((div & res) == 0) div <<= 1; //去最低位作为分组依据
        //分组异或
		int a = 0, b = 0;
		for (int n : nums)
			if (div & n)
				a ^= n;
			else
				b ^= n;
		return vector<int>{a, b};
	}
};
