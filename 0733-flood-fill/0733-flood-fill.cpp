class Solution {
public:
    
     void dfs(int x,int y,int m,int n,vector<vector<int>>& ans,vector<vector<int>>& image,int newcolor,int inicolor)
    {
        ans[x][y]=newcolor;
         
      int dx[]={0,-1,0,1};
      int dy[]={1,0,-1,0};
      
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 &&nx<n && ny<m && image[nx][ny]==inicolor && ans[nx][ny]!=newcolor)
            {
                ans[nx][ny]=newcolor;
             dfs(nx,ny,m,n,ans,image,newcolor,inicolor); 
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int n=image.size();
        int m=image[0].size();
     
        vector<vector<int>>ans=image;
         dfs(sr,sc,m,n,ans,image,color,image[sr][sc]);        
        return ans;
    }
};