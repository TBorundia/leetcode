class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int fresh = 0;
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
                if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int cnt = 0;
        int t=0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            t = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                    cnt++;
                }
            }
        }
        if (fresh != cnt)
            return -1;
        return t;
    }
};