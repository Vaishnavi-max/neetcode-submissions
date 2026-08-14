class Solution {
public:
    vector<vector<bool>>dp;
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        dp.resize(n,vector<bool>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            cnt++;
            
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(s[i]==s[j] && (l==2||dp[i+1][j-1])){
                    dp[i][j]=true;
                    cnt++;
                }else{
                    dp[i][j]=false;
                }
            }
        }
        return cnt;
    }
};
