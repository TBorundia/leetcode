class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        string res;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cnt>0) res+=s[i];
                cnt++;
            }
            else{
                if(cnt>1) res+=s[i];
                cnt--;
            }
        }
        return res;
    }
};