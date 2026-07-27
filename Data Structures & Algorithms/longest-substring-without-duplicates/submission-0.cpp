class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=0;
        unordered_map<int,int>freq;
        int len=0;
        while(r<n){
            freq[s[r]]++;
            while(freq[s[r]]>1){
                
                freq[s[l]]--;
                l++;
                    
                
                
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};
