class Solution {
public:
    
    void dfs(int x,int y,int m,int n,vector<vector<char>>& grid)
    {
        
      int dx[]={0,-1,0,1};
      int dy[]={1,0,-1,0};
      
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 &&nx<n && ny<m && grid[nx][ny]=='1')
            {
                grid[nx][ny]='$';
                dfs(nx,ny,m,n,grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
       int n=grid.size();
        int m=grid[0].size();
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,m,n,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};