class Solution {
public:
    void floydwarshall(vector<vector<long long>>&adj)
    {
        for(int via=0;via<26;via++)
        {
         for(int i=0;i<26;i++)
         {
             for(int j=0;j<26;j++)
             {
               if (adj[i][via] < 1e9 && adj[via][j] < 1e9) {
                        adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                    }
             }
         }
        }
    }
    
    long long solve(vector<vector<long long>>&adj,string source, string target)
    {
            if (source.length() != target.length()) return -1;
        long long mincost=0;
        for(int i=0;i<source.length();i++)
        {
            if(source[i]==target[i])continue;
            if(adj[source[i]-'a'][target[i]-'a']==1e9)return -1;
            
            mincost+=adj[source[i]-'a'][target[i]-'a'];
        }
        return mincost;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<long long>>adj(26,vector<long long>(26,1e9));
        
       for(int i=0;i<original.size();i++)
       {
           adj[original[i]-'a'][changed[i]-'a']=min((long long)cost[i], adj[original[i]-'a'][changed[i]-'a']);
       }
        for(int i=0;i<26;i++)
        {
            adj[i][i]=0;
        }
        
        floydwarshall(adj);
        
        return solve(adj,source,target);
    }
};