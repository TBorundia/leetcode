class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int max_seq = 1, cnt = 1;
        if(n==0) return 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]){
                continue;
            }
            if (nums[i] == nums[i - 1] + 1) {
                cnt++;
            } 
            else {
                max_seq = max(max_seq, cnt);
                cnt = 1;
            }
        }
        max_seq = max(max_seq, cnt);
        return max_seq;
    }
};