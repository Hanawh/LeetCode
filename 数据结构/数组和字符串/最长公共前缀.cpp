/*
输入: ["flower","flow","flight"]
输出: "fl"
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         string s;
        int nums = strs.size();
        if(nums < 1) return s;
        for(int i=0; i<strs[0].size(); ++i){ //based on 1
            char c=strs[0][i]; //获取当前比较字符
            int cnt=1; //字符相同的个数
            for(int j=1; j<nums; ++j){
                //判断大小是否满足
                if(strs[j].size()<i+1) return s;
                if(strs[j][i] == c) ++cnt;
            }
            if(cnt==nums) s.push_back(c);
            else return s;
        } 
        return s;
    }
};
