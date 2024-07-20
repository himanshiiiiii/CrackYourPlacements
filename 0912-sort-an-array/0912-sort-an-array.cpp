class Solution {
public:
    void merge(vector<int>& nums,int l,int h,int mid)
    {
        int left=l ,right=mid+1;
        vector<int>ans;
        while(left<=mid && right<=h)
        {
            if(nums[left]<nums[right])
            {
                ans.push_back(nums[left]);
                left++;
            }
            else
            {
                    ans.push_back(nums[right]);
                right++;
            }
        }
         while(left<=mid )
        {
             ans.push_back(nums[left]);
                left++;
        }
         while(right<=h)
        {
            
             ans.push_back(nums[right]);
                right++;
         }
        
        for(int i=l;i<=h;i++)
        nums[i]=ans[i-l];
        
    }
    void mergesort(vector<int>& nums,int l,int h)
    {
        if(l>=h)return;
        
        int mid=l+(h-l)/2;
        
        mergesort(nums,l,mid);
         mergesort(nums,mid+1,h);
        merge(nums,l,h,mid);
            
    }
    
    vector<int> sortArray(vector<int>& nums) {
       
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};