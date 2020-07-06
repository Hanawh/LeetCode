class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long> > link_two;
        priority_queue<long,vector<long>,greater<long> > link_three;
        priority_queue<long,vector<long>,greater<long> > link_five;

        long res = 1;
        while(--n){
            link_two.push(2*res);
            link_three.push(3*res);
            link_five.push(5*res);
            res = min(min(link_two.top(), link_three.top()), link_five.top());
            if(link_two.top()==res) link_two.pop();
            if(link_three.top()==res) link_three.pop();
            if(link_five.top()==res) link_five.pop();
        }
        return res;
    }
};
