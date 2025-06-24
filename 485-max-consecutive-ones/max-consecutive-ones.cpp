class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int max_cnt=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
            }
            else{
                max_cnt=max(max_cnt,cnt);
                cnt=0;
            }
        }
        max_cnt=max(max_cnt,cnt);
        return max_cnt;
    }
};