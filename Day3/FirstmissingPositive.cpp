class Solution {
public:
    int firstMissingPositive(vector<int>& nums) { 
      int n=nums.size();
     
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            if(ele>=1&&ele<n)
            {
                int pos=ele-1;
                if(nums[pos]!=pos+1)
                {
                    swap(nums[pos],nums[i]);
                        i--;
                }
            }
        }
        for(int i=0;i<n;i++)
        {cout<<nums[i]<<" ";
            if(nums[i]!=i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};