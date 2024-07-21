class Solution {
public:
    
    bool isPossible(int currsum,vector<int>& nums,int n, int k)
    {
        
        int numssum=0;
        int count=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]+numssum<=currsum)
            {
                numssum+=nums[i];
            }
            else
            {
                count++;
                numssum=nums[i];
            }
            if(count>k)return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int l=*max_element(nums.begin(),nums.end());
        int h=0;
        int n=nums.size();
        if(k>n)return -1;
        for(int i=0;i<n;i++)
        {
            h+=nums[i];
        }
        int ans=0;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(isPossible(mid,nums,n,k))
            {
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};