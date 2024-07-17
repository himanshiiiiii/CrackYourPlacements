class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
           if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++)
            {
                 if(j>i+1 && nums[j]==nums[j-1])continue;
                int third=j+1;
                int four=n-1;
                
                while(third<four)
                {
                    long long sum=nums[i];
                      sum+=nums[j];
                          sum+=nums[third];
                    sum+=nums[four];
                    if(sum==target)
                    {
                         ans.push_back({nums[i],nums[j],nums[third],nums[four]});
                         third++;
                          four--; 
                        while(third<four && nums[third]==nums[third-1])
                        third++;
                      while(third<four && nums[four]==nums[four+1])
                        four--; 
   
                    }
                    else if(sum>target)
                        four--;
                    
                    else
                        third++;
                }
            }
        }
        return ans;
    }
};