class Solution {
public:
    int n;
    vector<vector<int>>dp;
    // bool is_possible(int idx,int sum,vector<int>&nums){
    //     if(sum==0){
    //         return 1;
    //     }
    //     if(idx>=n||sum<0){
    //         return 0;
    //     }
    //     if(dp[idx][sum]!=-1){
    //         return dp[idx][sum];
    //     }
    //     int take=is_possible(idx+1,sum-nums[idx],nums);
    //     int not_take=is_possible(idx+1,sum,nums);
    //     return dp[idx][sum]=take||not_take;
    // }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        n=nums.size();
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int reqd=sum/2;
        // dp.resize(n+1,vector<int>(reqd+1,-1));
        // return is_possible(0,reqd,nums);
        dp.resize(n+1,vector<int>(reqd+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int sum=reqd;sum>=0;sum--){
                bool take = 0;
                if (sum >= nums[i]) {
                    take = dp[i + 1][sum - nums[i]];
                }
                bool not_take =dp[i + 1][sum];
                dp[i][sum]= take || not_take;
            }
        }
        return dp[0][reqd];
    }
};
