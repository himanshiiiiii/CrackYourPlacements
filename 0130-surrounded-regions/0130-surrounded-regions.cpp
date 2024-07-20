class Solution {
public:
     void dfs(int l,int h,int n,int m,vector<vector<char>>& board,vector<vector<int>>&vis)
    {
        if(l<0 ||h<0||l>=n|| h>=m || board[l][h]!='O' ||vis[l][h]==1)
        return ;
        
        
        vis[l][h]=1;
         dfs(l+1,h,n,m,board,vis);
        dfs(l-1,h,n,m,board,vis);
        dfs(l,h+1,n,m,board,vis);
        dfs(l,h-1,n,m,board,vis);
    }
    void solve(vector<vector<char>>& board) {
        
      
        int n=board.size();
        if(n==0)return;
        int m=board[0].size();
          vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            //first row
            if(board[0][j]=='O' && !vis[0][j])
                dfs(0,j,n,m,board,vis);
            
        //last row
            if(board[n-1][j]=='O' && !vis[n-1][j])
                dfs(n-1,j,n,m,board,vis);
        
        }
        
        for(int i=0;i<n;i++)
        {
            //first col
            if(board[i][0]=='O' && !vis[i][0])
                dfs(i,0,n,m,board,vis);
            
        //last col
            if(board[i][m-1]=='O' && !vis[i][m-1])
                dfs(i,m-1,n,m,board,vis);
        
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' &&!vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};