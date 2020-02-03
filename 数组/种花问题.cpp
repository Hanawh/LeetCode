class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if(n == 0) return true;
        if(len == 1) {
            if(flowerbed[0] == 0) return true;
            else return false;
        }
        for(int i = 0; i < len; ++i){
            if(i == 0){
                if(flowerbed[i] == 0 and flowerbed[i+1] == 0){
                    flowerbed[i]=1;
                    n--;
                }
            }
            else if(i+1 < len and flowerbed[i] == 0 and flowerbed[i+1] == 0 and flowerbed[i-1] == 0){
                n--;
                flowerbed[i] = 1;
            }
            else if(i == len-1){
                if(flowerbed[i-1] == 0 and flowerbed[i] == 0){
                    flowerbed[i]=1;
                    n--;
                }
            }
            if(n==0) return true;
        }
        if(n==0) return true;
        return false;
    }
};
