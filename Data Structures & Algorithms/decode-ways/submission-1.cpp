class Solution {
public:
    vector<int>dp;
    int numDecodings(string s) {
        int n = s.size();
        dp.resize(n, 0);

        // return solve(0, s);
        dp[n-1]=1;
        if(s[n-1]=='0'){
            dp[n-1]=0;
        }
        for(int i=n-2;i>=0;i--){
            if (s[i] == '0'){
                dp[i] = 0;
                continue;
            }
            int w=dp[i+1];
            if(i+1<n){
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                if (num >= 10 && num <= 26){
                    if(i+2<n){
                        w += dp[i+2];
                    }else{
                        w+=1;
                    }
                    
                }
            }
            dp[i]=w;
        }
        return dp[0];
    }
};
