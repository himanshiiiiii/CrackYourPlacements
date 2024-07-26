class Solution {
public:
    
    void  floydWarshall(int n,vector<vector<int>>&SPM)
    {
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    SPM[i][j]=min(SPM[i][j],SPM[i][via]+SPM[via][j]);
                }
            }
        }
    }
    
    
    int city(int n,vector<vector<int>>&SPM,int D)
    {
        int maxicity=-1;
        int leastreachcount=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
           int reachcount=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && SPM[i][j]<=D)
                    reachcount++;
            }
            if(reachcount<=leastreachcount)
            {
                leastreachcount=reachcount;
                maxicity=i;
            }
        }
        return maxicity;
        
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>SPM(n,vector<int>(n,1e9+7));
        
        for(int i=0;i<n;i++)
            SPM[i][i]=0;
        
        
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            SPM[u][v]=wt;
            SPM[v][u]=wt;
        }
         
        floydWarshall(n,SPM);
        
        return city(n,SPM,distanceThreshold);
            
            
    }
};