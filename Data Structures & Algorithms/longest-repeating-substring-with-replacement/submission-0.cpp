class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int len=0,maxf=0,l=0,r=0;
        unordered_map<char,int>freq;
        while(r<n){
            freq[s[r]]++;
            maxf=max(maxf,freq[s[r]]);
            while(r-l+1-maxf>k){
                freq[s[l]]--;
                
                l++;
                
                
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};
