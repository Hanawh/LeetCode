class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int col = nums[0].size();
        if(r*c!=row*col) return nums;
        vector<vector<int> > res(r, vector<int>(c));
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                res[(i*col+j)/c][(i*col+j)%c]=nums[i][j];
            }
        }
        return res;
    }
};
