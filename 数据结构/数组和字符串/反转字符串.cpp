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
        if(n == 0) return;
        auto i = s.begin();
        auto j = s.end()-1;
        int cnt = 0;
        while(cnt < n/2){
            char temp = *i;
            *i = *j;
            *j = temp;
            i++;
            j--;
            cnt++;
        }
    }
};
int main()
{
    vector<char> s{'h','a','n','n','a','h'};
    Solution().reverseString(s);
    for(auto i:s) cout<<i<<" ";
    return 0;
};
