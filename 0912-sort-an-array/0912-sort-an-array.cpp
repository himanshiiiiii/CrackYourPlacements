class Solution {
public:
    void merge(vector<int>& nums,int l,int h,int mid)
    {
        int n=nums.size();
        int left=l,right=mid+1;
        int k=0;
        vector<int>temp(h-l+1);
        while(left<=mid&&right<=h)
        {
            if(nums[left]<nums[right])
                temp[k++]=nums[left++];
            else
                temp[k++]=nums[right++];
        }
         while(right<=h)
        {
                temp[k++]=nums[right++];
        }
         while(left<=mid)
        {
                temp[k++]=nums[left++];
        }
        
        for(int i=l;i<=h;i++)
        {
            nums[i]=temp[i-l];
        }
        
       
        
    }
    void mergesort(vector<int>& nums,int l,int h)
    {
        
     if(l<h)
          {
              int mid=l+(h-l)/2;
              mergesort(nums,l,mid);
              mergesort(nums,mid+1,h);
              merge(nums,l,h,mid);
          }
    }
    
    vector<int> sortArray(vector<int>& nums) {
       
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};