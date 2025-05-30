class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>> &arr, vector<vector<int>> &dp) {
        if (i == n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = arr[i][j] + solve(i + 1, j, n, arr, dp);
        int diagonal = arr[i][j] + solve(i + 1, j + 1, n, arr, dp);
        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, n, arr, dp);
    }
};