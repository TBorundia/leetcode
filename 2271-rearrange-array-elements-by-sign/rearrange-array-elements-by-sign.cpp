class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int s=nums.size();
        vector<int> v(s,0);
        int p=0,n=1;
        for(int i=0;i<s;i++){
            if(nums[i]>0){
                v[p]=nums[i];
                p+=2;
            }
            else{
                v[n]=nums[i];
                n+=2;
            }
        }
        return v;
    }
};