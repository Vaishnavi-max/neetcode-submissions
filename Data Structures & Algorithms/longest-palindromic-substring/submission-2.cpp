class Solution {
public:
    vector<vector<bool>>dp;
    // bool solve(int i,int j,const string &s){
    //     if(i>=j){
    //         return true;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(s[i]!=s[j]){
    //         return dp[i][j] =false;
    //     }
    //     return dp[i][j] =solve(i+1, j-1, s);
    // }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=0,sp=0;
        dp.resize(n,vector<bool>(n,0));
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(solve(i,j,s)==true){
        //             if(j-i+1>maxlen){
        //                 maxlen=j-i+1;
        //                 sp=i;
        //             }
        //         }
        //     }
        // }
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            maxlen=1;
            
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(s[i]==s[j] && (l==2||dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        sp=i;
                    }
                }else{
                    dp[i][j]=false;
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};