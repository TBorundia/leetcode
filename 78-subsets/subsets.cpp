class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int s=(1<<n);
        for(int i=0;i<s;i++){
            vector<int> v;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)) v.push_back(nums[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};