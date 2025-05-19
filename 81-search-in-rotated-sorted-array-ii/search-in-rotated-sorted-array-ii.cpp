class Solution {
public:
    bool search(vector<int>& arr, int target) {
        auto it = find(arr.begin(), arr.end(), target);
        return it != arr.end();
    }
};
