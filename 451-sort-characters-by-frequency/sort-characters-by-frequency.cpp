class Solution {
public:
    static bool compare(pair<char,int>& a,pair<char,int>& b){
        return a.second>b.second;
    }
    string frequencySort(string s) {

        string res="";
        unordered_map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }

        vector<pair<char,int>> v(mpp.begin(),mpp.end());

        sort(v.begin(),v.end(),compare);

        for(auto& c:v){
            res+=string(c.second,c.first);
        }
        return res;
    }
};