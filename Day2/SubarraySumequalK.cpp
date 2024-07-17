class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        int sum=0;
        m[0]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            
            int val=sum-k;
            if(m.find(val)!=m.end())
            {
                ans+=m[val];
            }
            m[sum]++;
        }
        return ans;
    }
};