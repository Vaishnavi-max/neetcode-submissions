class Solution {
public:
    int n;
    bool ispossib(int mid,vector<int>&piles,int h){
        long long t=0;
        for(int i=0;i<n;i++){
            t+=(piles[i]+mid-1)/mid;
        }
        return t<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        n=piles.size();
        sort(piles.begin(),piles.end());
        int l=1,hi=piles[n-1];
        int ans=0;
        while(l<=hi){
            int mid=l+(hi-l)/2;
            if(ispossib(mid,piles,h)){
                ans=mid;
                hi=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
