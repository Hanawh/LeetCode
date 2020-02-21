class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 1, j = nums.size()-1;
        while(i<j) //[i,j]
        {
            int mid = i+(j-i)/2;
            //小于等于mid的数最多有mid个
            int cnt = 0;
            for(auto &i : nums){
                if(i<=mid) cnt++;
            }
            
            if(cnt == mid){ //[mid+1,j]
                i = mid + 1;
            }
            else if(cnt > mid){ //[i,mid]
                j = mid;
            }
            else if(cnt < mid){
                i = mid + 1;
            }
            cout<<i<<" "<<j;
        }
        return i;
    }
};
