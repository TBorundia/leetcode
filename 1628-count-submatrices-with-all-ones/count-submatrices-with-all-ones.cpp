class Solution 
{
    struct YT
    { int A, u, b, h; };
    
public:
    int numSubmat(vector<vector<int>>& m) 
    {
        int out{};
        vector t(size(m)+1, vector(size(m[0])+1, YT{}));
        for(int i{}; i<size(m); ++i)
            for(int j{}; j<size(m[0]); ++j)
                if(m[i][j]) 
                {
                    int b  = t[i+1][j].b,
                        u  = t[i][j+1].u, 
                        h  = t[i][j+1].h, 
                        A0 = t[i][j]  .A,
                        A1 = t[i][j+1].A,
                        A2 = t[i+1][j].A;
                    
                    out += (t[i+1][j+1] = !u or u>b ? YT{(b+1)*(h+1), b+1, b+1, h+1} : YT{A1+A2-A0+1, u, b+1, h+1}).A;
                }
        return out;
    }
};