class Solution {
public:
    void solve(int idx,vector<int>& candidates, int target, vector<int>&res,vector<vector<int>>&ans)
    {
        int n=candidates.size();
     
            if(target==0)
            { 
                ans.push_back(res);
            return ;
        }
        //take
        for(int i=idx;i<n;i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])continue;
        if(candidates[i]>target)break;
       
        res.push_back(candidates[i]);
        solve(i+1,candidates,target-candidates[i],res,ans);
        res.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
         vector<vector<int>>ans;
        vector<int>res;
        solve(0,candidates,target,res,ans);
        
        return ans;
        
    }
};