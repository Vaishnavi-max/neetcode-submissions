class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int p=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<=buy){
                buy=min(buy,prices[i]);
            }else{
                p=max(p,abs(prices[i]-buy));
            }
        }
        return p;
    }
};
