class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>freq;
        int n=t.size();
        for(auto it:t){
            freq[it]++;
        }
        int reqd=freq.size();
        int l=0,r=0;
        int maxlen=INT_MAX;
        int cnt=0;
        int st=0;
        while(r<s.size()){
            freq[s[r]]--;
            if(freq[s[r]]==0){
                cnt++;
            }
            while(cnt==reqd){
                //shrink
                if(r-l+1<maxlen){
                    maxlen=r-l+1;
                    st=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(maxlen==INT_MAX){
            return "";
        }
        return s.substr(st,maxlen);

    }
};
