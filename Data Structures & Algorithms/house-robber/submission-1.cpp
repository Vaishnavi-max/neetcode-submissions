class Solution {
public:
    int n;
    vector<int>dp;
    // int func(int i,vector<int>&nums){
    //     if(i>=n){
    //         return 0;
    //     }
    //     if(i==n-1){
    //         return nums[n-1];
    //     }
    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }
    //     int take=nums[i]+func(i+2,nums);
    //     int not_take=0+func(i+1,nums);
    //     return dp[i]=max(take,not_take);
    // }
    int rob(vector<int>& nums) {
        n=nums.size();
        // dp.resize(n+1,-1);
        // dp[n]=0;
        // dp[n-1]=nums[n-1];
        int h2=0;
        int h1=nums[n-1];
        for(int i=n-2;i>=0;i--){
            // int take=nums[i]+dp[i+2];
            int take=nums[i]+h2;
            int not_take=h1;
            // dp[i]=max(take,not_take);
            int temp=max(take,not_take);
            h2=h1;
            h1=temp;
        }
        return h1;
    }
};
