class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, k, n, current, result);
        return result;
    }
    
private:
    void backtrack(int start, int k, int n, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k && n == 0) {
            result.push_back(current);
            return;
        }
        if (n < 0 || current.size() > k) return;
        
        for (int i = start; i <= 9; ++i) {
            current.push_back(i);
            backtrack(i + 1, k, n - i, current, result);
            current.pop_back();
        }
    }
};