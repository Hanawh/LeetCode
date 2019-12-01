/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time
*/

#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    stack<int> s1;//s1储存所有元素
    stack<int> s2;//s2储存最小元素
  /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x); 
        if (s2.empty() or x <= getMin()) s2.push(x);
    }
    
    void pop() {
        if (s1.top() == getMin()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }  
};
