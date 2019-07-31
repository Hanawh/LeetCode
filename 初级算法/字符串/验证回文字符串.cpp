/*
输入: "A man, a plan, a canal: Panama"
输出: true

输入: "race a car"
输出: false
 */
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        auto a = s.begin(), b = s.end()-1; 
        cout<<*a<<endl<<*b<<endl;
        while(a<b)
        {
            while (a<b && !isalnum(*a)) a++;
            while (a<b && !isalnum(*b)) b--;
            if(tolower(*a) != tolower(*b)) return false;
            if(a == b) return true;
            a++;
            b--;
        };
        return true;
    }
};
int main()
{
    string s1 = "A man, a plan, a canal: Panama",  s2 = "race a car";
    cout << boolalpha << Solution().isPalindrome(s1) << endl << Solution().isPalindrome(s2)<< endl;
    return 0;
}
