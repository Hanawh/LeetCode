class Solution {
public:

    int cumulate(vector<int>& arr, int val){
        int ret = 0;
        for (const int& num: arr) {
            ret += (num >= val ? val : num);
        }
        return ret;
    }

    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        if(target == 0) return 0;
        float mean = float(target) / float(len);
        if(arr[0] >= mean){
            int sum1 = int(mean) * len;
            int sum2 = (int(mean) + 1) * len;
            return abs(sum1 - target) <= abs(sum2 - target) ? int(mean) : int(mean) + 1;
        } 
        //计算出前缀和 以及最大的数
        vector<int> cusum(len+1);
        int maxval = arr[len-1];
        for(int i = 1; i < len; ++i){ 
            cusum[i] =  arr[i-1] + cusum[i-1];
        }
        
        int left = 1, right = maxval;
        while(left < right){
            int mid = left + (right - left) / 2;
            //找到刚好大于等于arr[mid]的地方 下标为iter-arr.begin()
            auto iter = lower_bound(arr.begin(), arr.end(), mid);
            //计算之后的和
            int cur = cusum[iter-arr.begin()] + (arr.end()-iter) * mid;
            if(cur < target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }

        int temp1 = cumulate(arr, left);
        int temp2 = cumulate(arr, left-1);

        return abs(temp1- target) < abs(temp2 - target) ? left : left - 1;

        
    }

};


class Solution {
public:
    int cumulate(vector<int>& arr, int val){
        int ret = 0;
        for (const int& num: arr) {
            ret += (num >= val ? val : num);
        }
        return ret;
    }

    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        if(target == 0) return 0;
        float mean = float(target) / float(len);
        if(arr[0] >= mean){
            int sum1 = int(mean) * len;
            int sum2 = (int(mean) + 1) * len;
            return abs(sum1 - target) <= abs(sum2 - target) ? int(mean) : int(mean) + 1;
        } 

        int tmp = target;
        int ret = arr[len-1];
        for(int i = 0; i < len; ++i){
            //如果当前值小于平均值，只能寄希望于后面的数
            if(arr[i] < mean) {
                mean = float(tmp - arr[i])/float(len - i - 1);
                tmp = tmp - arr[i];
            } 
            else{
                ret = mean;
                break;
            }
        }

        int sum1 = cumulate(arr, ret);
        int sum2 = cumulate(arr, ret+1);
        return abs(sum1 - target) <= abs(sum2 - target) ? ret : ret + 1;
    }
};
