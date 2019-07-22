/*
s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 */
#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution
{
public:
   int firstUniqChar(string s) {
        map<char,int> temp;
        for(int i=0; i<s.size(); ++i) temp[s[i]]++;
        for(int i=0; i<s.size(); ++i)
        {
             map<char,int>::iterator iter=temp.find(s[i]); //返回位置
             if(iter->second==1) return i;
        }
        return -1;
    }
};
int main()
{
    string s1="leetcode", s2="loveleetcode";
    int result1=Solution().firstUniqChar(s1);
    int result2=Solution().firstUniqChar(s2);
    cout<<result1<<endl<<result2<<endl;
    return 0;
}
