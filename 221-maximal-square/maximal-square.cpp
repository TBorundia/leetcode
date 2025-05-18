class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxSquare = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min({
                        i > 0 ? dp[i-1][j] : 0,
                        j > 0 ? dp[i][j-1] : 0,
                        i > 0 && j > 0 ? dp[i-1][j-1] : 0
                    }) + 1;
                    maxSquare = max(maxSquare, dp[i][j]);
                }
            }
        }

        return maxSquare * maxSquare;
    }
};