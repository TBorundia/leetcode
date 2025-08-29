class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> res(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    res[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }

        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop(); res[r][c]=d;

            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && mat[nr][nc]!=0){
                    q.push({{nr,nc},d+1});
                    vis[nr][nc]=1;
                    // res[nr][nc]=d+1;
                }
            }
        }
        return res;
    }
};