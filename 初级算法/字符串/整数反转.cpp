/*
输入: -123
输出: -321

输入: 120
输出: 21
 */
#include<iostream>
using namespace std;
const int IMAX=0x7fffffff;
const int IMIN=(-0x7fffffff-1); 
class Solution
{
public:
    int reverse(int x) {
        int temp=0;
        do
        {
            if(temp>(IMAX/10) or temp<(IMIN/10)) return 0;
            temp=temp*10+x%10;
            x /= 10;
        } while (x);
        return temp;
    }
};
int main()
{
    int x1=-123, x2=120;
    int result1=Solution().reverse(x1);
    int result2=Solution().reverse(x2);
    cout<<result1<<endl<<result2<<endl;
    return 0;
}
