class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int n = 0;
        while(candies>0){
            for(int i=0; i<num_people; ++i){
                if(candies >= i+1+n) {res[i] += i+1+n; candies = candies - (i+1+n);}
                else {res[i] += candies; candies = 0;}
                if(candies <= 0) break; 
            }
            n = n + num_people;
        }
        return res;
    }
};
