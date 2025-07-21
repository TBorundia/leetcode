class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        int n=s.length();
        if(s.length()!=t.length()) return false;
        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            v[c]++;
        }
        for(int i=0;i<n;i++){
            int c=t[i]-'a';
            if(v[c]<=0) return false;
            else{
                v[c]--;
            }
        }
        return true;
    }
};