class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int r=0,l=0;
        int zero=0,maxOne=0;
        while(r<n){
            if(nums[r]==0) zero++;
            if(zero>k){
                if(nums[l]==0) zero--;
                l++;
            } 
            if(zero<=k) maxOne=max(maxOne,r-l+1);
            r++;
        }
        return maxOne;
    }
};