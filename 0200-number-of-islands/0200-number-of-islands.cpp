class Solution {
public:
    
    void dfs(int l,int h,int m,int n,vector<vector<char>>& grid)
    {
        if(l<0 ||h<0||l>=n|| h>=m || grid[l][h]!='1')
        return ;
        
        
        grid[l][h]='$';
         dfs(l+1,h,m,n,grid);
        dfs(l-1,h,m,n,grid);
        dfs(l,h+1,m,n,grid);
        dfs(l,h-1,m,n,grid);
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