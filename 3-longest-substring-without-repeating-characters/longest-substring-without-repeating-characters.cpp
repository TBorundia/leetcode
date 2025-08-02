class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            unordered_map<char,int> mpp;
            for(int j=i;j<n;j++){
                if(mpp[s[j]]++) break;
                else maxLen=max(maxLen,j-i+1);
            }
        }
        return maxLen;
    }
};