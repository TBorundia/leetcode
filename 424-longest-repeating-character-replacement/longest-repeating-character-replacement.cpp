class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxLen=0;
        int l=0,r=0;
        int maxFreq=0;
        unordered_map<char,int> mpp;
        while(r<n){
            mpp[s[r]]++;
            maxFreq=max(maxFreq,mpp[s[r]]);
            if((r-l+1)-maxFreq<=k){
                maxLen=max(maxLen,r-l+1);
            }
            else{
                mpp[s[l]]--;
                l++;
            }
            r++;
        }
        return maxLen;
    }
};