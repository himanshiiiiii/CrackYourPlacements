class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>forprod(n);
        vector<int>backprod(n);
        forprod[0]=nums[0];
        backprod[0]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            forprod[i]=forprod[i-1]*nums[i];
        }
                for(int i=n-2;i>=0;i--)
        {
            backprod[n-i-1]=backprod[n-i-2]*nums[i];
        }
        reverse(backprod.begin(),backprod.end());
        vector<int>ans(n);
        ans[0]=backprod[1];
        ans[n-1]=forprod[n-2];
      for(int i=1;i<n-1;i++)
      {
          ans[i]=forprod[i-1]*backprod[i+1];
      }
        return ans;
    }
};