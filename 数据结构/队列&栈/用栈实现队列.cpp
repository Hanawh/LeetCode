class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = st1.top();
        st1.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        return st1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty();
    }
private:
    stack<int> st1,st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
