class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> vis(m,vector<int> (n,0));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                vis[0][i]=1;
            }
            if(board[m-1][i]=='O'){
                q.push({m-1,i});
                vis[m-1][i]=1;
            }
        }

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(board[i][n-1]=='O'){
                q.push({i,n-1});
                vis[i][n-1]=1;
            }
        }

        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O' && vis[nr][nc]==0){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }

        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};