class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n=str.size();
        string res;
        int i=0;
        for (int i = 0; i < str[0].length(); i++) {
            char c = str[0][i];
            for(int j=0;j<str.size();j++){
                if(i >= str[j].length() || c!=str[j][i]) return res;
            }
            res+=c;
        }
        return res;
    }
};