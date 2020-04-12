//方法一 小顶堆
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > smallHeap; //升序排列 
    int K;//维护一个容量为K的小顶堆，堆顶就是第k大的元素
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto num:nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if(smallHeap.size() < K){
            smallHeap.push(val);
        }
        else if(val > smallHeap.top()){
            smallHeap.pop();
            smallHeap.push(val);
        }
        return smallHeap.top();
    }
};

//方法二 二叉搜索树
