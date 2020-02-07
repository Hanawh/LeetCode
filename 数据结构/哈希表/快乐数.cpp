class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> tmp;
        while(n!=1){
            //各位求和
            int ans = 0;
            while(n>0)
            {
                ans += (n%10)*(n%10);
                n = n /10;
            }
            n = ans;
            
            if(tmp.count(n)) return false;
            tmp.insert(n);
        }
        return true;
    }
};
