class Solution {
public:
    int fun(vector<int>& nums, int goal){
        int l=0,r=0,cnt=0;
        int n=nums.size();
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(l<=r && sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums,goal)-fun(nums,goal-1);
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                v.push_back(0);
            }
            else{
                v.push_back(1);
            }
        }
        return (numSubarraysWithSum(v,k));
    }
};