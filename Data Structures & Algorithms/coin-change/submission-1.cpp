class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int func(int idx,int sum,vector<int>&coins){
        if(idx==n||sum<0){
            return INT_MAX;
        }
        if(sum==0){
            return 0;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        int take=INT_MAX;
        if(func(idx,sum-coins[idx],coins)!=INT_MAX){
            take=1+func(idx,sum-coins[idx],coins);
        }
        int not_Take=0+func(idx+1,sum,coins);
        return dp[idx][sum]=min(take,not_Take);
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        int ans= func(0,amount,coins);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};
