class Solution {
public:
    
    void solve(int start,vector<int>& nums,int n,vector<int>&res, vector<vector<int>>&ans)
    {
        
            ans.push_back(res);
          
        
        //take
        for(int i=start;i<n;i++)
        {
        if(i>start && nums[i]==nums[i-1])continue;
        res.push_back(nums[i]);
         solve(i+1,nums,n,res,ans);
        res.pop_back();
        
        }
  
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
       vector<vector<int>>ans;
        vector<int>res;
           sort(nums.begin(),nums.end());
        solve(0,nums,n,res,ans);
      return ans;
    }
};