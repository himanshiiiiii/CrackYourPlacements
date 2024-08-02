class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int countone=0;
        int n=nums.size();
        
            for(int i=0;i<n;i++)
            {
                if(nums[i]==1)
                    countone++;
            }
        
        //doubling the array to handle the case
        vector<int> extended(nums.begin(), nums.end());
        extended.insert(extended.end(), nums.begin(), nums.end());
       int l=0,r=0;
       int c=0;
        int mini=INT_MAX;
        while(r<n*2)
        {
            if(extended[r]==1)
                c++;
         
         if(r-l+1>countone)
         {
             if(extended[l]==1)
                 c--;
             l++;
         }
         if (r - l + 1 == countone) {
                mini = min(mini, countone - c);
            }
            r++;
        }
        return mini;
    }
};