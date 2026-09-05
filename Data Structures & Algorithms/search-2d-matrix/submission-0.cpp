class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,h=n*m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int r=mid/n,c=mid%n;
            int x=matrix[r][c];
            if(x==target){
                return true;
            }else if(x<target){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return false;
    }
};
