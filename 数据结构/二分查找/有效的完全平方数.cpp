class Solution {
public:
    bool isPerfectSquare(int num) {
        long i=0, j=num;
        while(i<=j) //[0,num]
        {
            long mid = i + (j-i)/2;
            if(mid * mid == num) return true;
            else if(mid * mid < num) i = mid + 1;
            else j = mid - 1;
        }
        return false;
    }
};

//1 4=1+3 9=1+3+5 16=1+3+5+7
class Solution 
{
public:
    bool isPerfectSquare(int num) 
    {
        int temp = 1;
        while(num > 0) 
        {
            num -= temp;
            temp += 2;
        }
        return num == 0;
    }
};
