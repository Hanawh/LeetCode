/*
输入: s = "anagram", t = "nagaram"
输出: true

输入: s = "rat", t = "car"
输出: false
 */
#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
   bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int temp_s[26] = {0};
        int temp_t[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            temp_s[s[i] - 'a']++;
            temp_t[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) 
        {
            if (temp_s[i] != temp_t[i]) return false;
        }
        return true;
    };
};

int main()
{
    string s1 = "anagram",  t1 = "nagaram", s2 = "rat",  t2 = "car";
    cout << boolalpha << Solution().isAnagram(s1, t1) << endl << Solution().isAnagram(s2, t2);
    return 0;
}
