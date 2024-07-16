class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int>m;
      vector<int>ans;
        
        for(int i=0;i<nums.size();i++)
        {
            int valtofind=target-nums[i];
            
            if(m.find(valtofind)!=m.end())
            {
                ans.push_back(i);
            ans.push_back(m[valtofind]);
        }
            else
                  m[nums[i]]=i;
                
        }
        return ans;
    }
};