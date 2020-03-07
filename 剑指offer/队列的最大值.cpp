//当一个元素进入队列的时候，它前面所有比它小的元素就不会再对答案产生影响
class MaxQueue {
public:
    MaxQueue() {
    }
    
    int max_value() {
        if(q.empty()) return -1;
        return max.front();
    }
    
    void push_back(int value) {
        while(!max.empty() and value > max.back()){
            max.pop_back();
        }
        max.push_back(value);
        q.push(value);

    }
    
    int pop_front() {
        if(q.empty()) return -1;
        int t=q.front();
        q.pop();
        if(t==max.front()) max.pop_front();
        return t;
    }
private:
    queue<int> q;
    deque<int> max;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
