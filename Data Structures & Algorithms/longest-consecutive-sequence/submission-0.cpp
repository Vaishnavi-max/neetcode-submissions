class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int maxcnt=0;
        for(auto x:st){
            if(!st.count(x-1)){
                int cnt=0;
                int it=x;
                while(st.count(it)){
                    cnt++;
                    it++;
                }
                maxcnt=max(maxcnt,cnt);
            }
            
        }
        return maxcnt;
    }
};
