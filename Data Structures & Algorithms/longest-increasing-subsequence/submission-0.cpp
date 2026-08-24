class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int solve(int i,int previdx,vector<int>&nums){
        if(i>=n){
            return 0;
        }
        if(dp[i][previdx+1]!=-1){
            return dp[i][previdx+1];
        }
        
        int take=0;
        if(previdx==-1||nums[i]>nums[previdx]){
            take=1+solve(i+1,i,nums);
        }
        int not_take=0+solve(i+1,previdx,nums);
        return dp[i][previdx+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums);
    }
};
