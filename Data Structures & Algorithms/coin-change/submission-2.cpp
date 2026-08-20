class Solution {
public:
    int n;
    vector<vector<int>>dp;
    // int func(int idx,int sum,vector<int>&coins){
    //     if(idx==n||sum<0){
    //         return INT_MAX;
    //     }
    //     if(sum==0){
    //         return 0;
    //     }
    //     if(dp[idx][sum]!=-1){
    //         return dp[idx][sum];
    //     }
    //     int take=INT_MAX;
    //     if(func(idx,sum-coins[idx],coins)!=INT_MAX){
    //         take=1+func(idx,sum-coins[idx],coins);
    //     }
    //     int not_Take=0+func(idx+1,sum,coins);
    //     return dp[idx][sum]=min(take,not_Take);
    // }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        dp.resize(n+1,vector<int>(amount+1,INT_MAX));
        // int ans= func(0,amount,coins);
        for(int i=n;i>=0;i--){
            dp[i][0]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int sum=1;sum<=amount;sum++){
                int take=INT_MAX;
                if(sum>=coins[i] && (dp[i][sum-coins[i]])!=INT_MAX){
                    take=1+dp[i][sum-coins[i]];
                }
                int not_Take=0+dp[i+1][sum];
                dp[i][sum]=min(take,not_Take);
            }
        }
        int ans= dp[0][amount];
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};
