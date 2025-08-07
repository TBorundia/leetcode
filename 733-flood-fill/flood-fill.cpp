class Solution {
public:
    void dfs(int iniColor,int color,vector<vector<int>>& image,vector<vector<int>>& ans,int r,int c){
        ans[r][c]=color;
        int n=image.size();
        int m=image[0].size();
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        for(int i=0;i<=3;i++){
            int nrow=r+delRow[i];
            int ncol=c+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=color){
                dfs(iniColor,color,image,ans,nrow,ncol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int iniColor=image[sr][sc];
        dfs(iniColor,color,image,ans,sr,sc);
        return ans;
    }
};