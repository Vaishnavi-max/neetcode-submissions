class Solution {
public:
    vector<int>dp;
    int n;
    // int func(int idx,vector<int>&cost){
    //     if(idx>=n){
    //         return 0;
    //     }
    //     if(dp[idx]!=-1){
    //         return dp[idx];
    //     }
    //     int take=cost[idx]+min(func(idx+1,cost),func(idx+2,cost));
    //     return dp[idx]=take;
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        dp.resize(n+2,0);
        // return min(func(0,cost),func(1,cost));
        dp[n]=dp[n+1]=0;
        for(int i=n-1;i>=0;i--){
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};
