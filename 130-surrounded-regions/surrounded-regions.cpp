class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[r][c]=1;

        int m=board.size();
        int n=board[0].size();

        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr=r+delr[i];
            int nc=c+delc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr,nc,vis,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int j=0;j<n;j++){
            if(!vis[0][j] && board[0][j]=='O') dfs(0,j,vis,board);
            if(!vis[m-1][j] && board[m-1][j]=='O') dfs(m-1,j,vis,board);
        }

        for(int i=0;i<m;i++){
            if(!vis[i][0] && board[i][0]=='O') dfs(i,0,vis,board);
            if(!vis[i][n-1] && board[i][n-1]=='O') dfs(i,n-1,vis,board);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};