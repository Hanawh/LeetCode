class Solution { //两个相同的数异或结果为0，一个数跟0异或是这个数本身
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        for(int i=0;i<nums.size();++i)
        {
            a ^= nums[i];
        }
        return a;
    }
}; //12ms 9.5MB

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> tmp;
        for(int i = 0; i < nums.size(); ++i){
            if(tmp.count(nums[i])) tmp.erase(nums[i]);
            else{
                tmp.insert(nums[i]);
            }
        }
        return *tmp.begin();
    }
}; //24ms 11.5MB
