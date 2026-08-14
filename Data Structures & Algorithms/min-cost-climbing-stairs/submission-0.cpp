class Solution {
public:
    vector<int>dp;
    int n;
    int func(int idx,vector<int>&cost){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take=cost[idx]+min(func(idx+1,cost),func(idx+2,cost));
        return dp[idx]=take;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        dp.resize(n,-1);
        return min(func(0,cost),func(1,cost));
    }
};
