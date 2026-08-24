class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<pair<int,int>>stk;
        vector<int>res(n,0);
        stk.push({temperatures[n-1],0});
        for(int i=n-2;i>=0;i--){
            int idx=n-1-i;
            while(!stk.empty() && temperatures[i]>=stk.top().first){
                stk.pop();
            }
            if(!stk.empty()){
                res[i]=abs(idx-stk.top().second);
            }
            stk.push({temperatures[i],idx});
        }
        return res;
    }
};
