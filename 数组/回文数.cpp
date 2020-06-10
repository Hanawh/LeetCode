class Solution {
public:
    bool isPalindrome(int x) {
        //反转一半数字，终止条件为反转后的数字大于等于前部分的数字
        if(x == 0) return true;
        if(x < 0 or x % 10 == 0) return false;
        int val = 0;
        while(x > val){
            val = val * 10 + x % 10;
            x = x / 10;
        }
        if(x == val or x == val / 10) return true;
        return false;
    }
};
