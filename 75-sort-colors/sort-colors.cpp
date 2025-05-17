class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int f=0,mid=0,l=n-1;
        while(mid<=l){
            if(nums[mid]==0){
                swap(nums[mid],nums[f]);
                mid++;
                f++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[l]);
                l--;
            }
        }
    }
};