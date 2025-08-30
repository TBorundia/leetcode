class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int j=0;j<n;j++){
            if(!vis[0][j] && grid[0][j]==1){
                q.push({0,j});
                vis[0][j]=1;
            } 
            if(!vis[m-1][j] && grid[m-1][j]==1){
                q.push({m-1,j});
                vis[m-1][j]=1;
            }
        }

        for(int i=0;i<m;i++){
            if(!vis[i][0] && grid[i][0]==1){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(!vis[i][n-1] && grid[i][n-1]==1){
                q.push({i,n-1});
                vis[i][n-1]=1;
            }
        }

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            int delr[]={-1,0,1,0};
            int delc[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};