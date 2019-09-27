/*
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public: 
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 1) return nums[0];

        //构建初始堆
        for(int i = nums.size()/2 - 1; i >= 0; i--){
            HeapSort(nums, i, size - 1);
        }
        for(int i = nums.size() - 1; i >= 0; i--){ //每一次将最大的和最后一个做交换
            exchange(nums[i], nums[0]);
            HeapSort(nums, 0, i - 1);
        }
        
        return nums[size - k];
    }
    
    void HeapSort(vector<int> &nums, int i, int size){
        int j = 2*i+1;
        while(j <= size){
            if(j < size && nums[j] < nums[j+1]){
                j++;
            }
            if(nums[i] > nums[j]) return;
            exchange(nums[i], nums[j]); //调整孩子节点
            i = j;
            j = 2*i+1;
        }
    }

    void exchange(int &s, int &t){
        if(s == t) return;
        int temp = s;
        s = t;
        t = temp;
    }
};

int main(){
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << Solution().findKthLargest(nums, k) << endl;
    return 0;
}
