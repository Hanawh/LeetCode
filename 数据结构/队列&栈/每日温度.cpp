/*
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = T.size();
        vector<int> res(size);
        stack<int> num;
        for(int i=0; i<size; ++i){//对每一个新元素判断与栈顶元素的大小，直至比该元素大
            while(!num.empty() and T[i] > T[num.top()]){
                int ind = num.top();
                num.pop();
                res[ind] = i-ind;
            }
            num.push(i);
        }
        return res;
    }
};
