class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        int i=0, j=len; 
        while(i<j)//[i,j)
        {
            int mid = i+(j-i)/2;
            if(letters[mid]>target) j=mid;
            else  i=mid+1; //find right
        }
        return letters[i%len];
    }
};

