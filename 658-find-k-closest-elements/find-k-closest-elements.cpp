class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() -1;

        while (l < r && (r - l + 1) > k) {
            int diffL = abs(arr[l] - x), diffR = abs(arr[r] - x);
            if (diffL > diffR) {
                l++; 
            } else if (diffR < diffL) {
                r--;
            } else {
                if (arr[l] < arr[r]) {
                    r--;
                } else {
                    l++;
                }
            }
        }

        vector<int> ans;
        for (int i = l; i <= r; ++i) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};