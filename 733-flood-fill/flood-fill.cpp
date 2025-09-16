class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& adj, int color, int ini,vector<vector<int>>& image) {
        adj[r][c] = color;

        int n = adj.size();
        int m = adj[0].size();

        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};

        for (int i = 0; i < 4; i++) {
            int nr = r + delr[i];
            int nc = c + delc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == ini && adj[nr][nc]!=color) {
                dfs(nr, nc, adj, color, ini,image);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> adj = image;
        int ini = image[sr][sc];

        dfs(sr, sc, adj, color, ini,image);
        return adj;
    }
};