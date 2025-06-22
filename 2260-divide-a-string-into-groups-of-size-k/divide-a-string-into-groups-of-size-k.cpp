class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();

        string temp;
        vector<string> ans;

        for (int i = 0; i < n; i = i + k) {
            temp=s.substr(i,k);

            while(temp.size()!=k)
            {
                temp.push_back(fill);
            }

            ans.push_back(temp);
            temp = "";
        }

        return ans;
    }
};