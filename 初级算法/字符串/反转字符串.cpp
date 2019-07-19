/*
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0; i<n/2; ++i)
        {
            char temp=s[i];
            s[i]=s[n-1-i];
            s[n-1-i]=temp;
        }
    }
};
int main()
{
    vector<char> s{'h','e','l','l','o'};
    Solution().reverseString(s);
    for(auto i:s) cout<<i<<" ";
    return 0;
}
