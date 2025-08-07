class Solution {
public:
    void bfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& visited){
        visited[r][c]=1;
        queue<pair<int,int>> q;
        q.push({r,c});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            int rr[4]={-1,0,1,0};
            int cc[4]={0,1,0,-1};
            for(int k=0;k<=3;k++){
                    int row=i+rr[k];
                    int col=j+cc[k];
                    if(row>=0 && row<n && col>=0 && col<m && !visited[row][col] && grid[row][col]=='1'){
                        visited[row][col]=1;
                        q.push({row,col});
                    }
                
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int cnt=0;
        vector<vector<int>>visited(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return cnt;
    }
};