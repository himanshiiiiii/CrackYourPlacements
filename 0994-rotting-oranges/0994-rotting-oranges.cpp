class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int frshcnt=0;
        queue<pair<pair<int,int>,int>>q;
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                 if(grid[i][j]==1)
                 frshcnt++;            
            }
        }
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        int pshcnt=0;
        int time=0;
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                
                if(nx>=0 &&ny>=0 &&nx<n && ny<m &&vis[nx][ny]!=2 && grid[nx][ny]==1)
                {
                    q.push({{nx,ny},t+1});
                    vis[nx][ny]=2;
                    pshcnt++;
                }
            }
        }
        if(pshcnt!=frshcnt) return -1;
        
        return time;
    }
};