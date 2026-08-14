class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i,int j,const string &s){
        if(i>=j){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]!=s[j]){
            return dp[i][j] =false;
        }
        return dp[i][j] =solve(i+1, j-1, s);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=0,sp=0;
        dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s)==true){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};