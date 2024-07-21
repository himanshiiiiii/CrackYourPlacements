class Solution {
public:
    void merge(int l,int h,vector<pair<int,int>>&v,vector<int>&count,int mid)
    {
        vector<pair<int,int>>temp(h-l+1);
        int i=l;
        int j=mid+1;
        int k=0;
        
        while(i<=mid && j<=h)
        {
            if(v[i].first<=v[j].first)
            {
                temp[k++]=v[j++];
            }
            else
            {
                count[v[i].second]+=h-j+1;
                temp[k++]=v[i++];
            }
        }
         while(i<=mid)
        {
                temp[k++]=v[i++];
        }
         while( j<=h)
        {
                temp[k++]=v[j++];   
        }
        for(int i=l;i<=h;i++)
        {
            v[i]=temp[i-l];
        }
    }
    void mergesort(int l,int h,vector<pair<int,int>>&v,vector<int>&count)
    {
        if(l<h)
        {
            int mid=l+(h-l)/2;
            mergesort(l,mid,v,count);
             mergesort(mid+1,h,v,count);
            merge(l,h,v,count,mid);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        vector<pair<int,int>>v(n);
        
        for(int i=0;i<n;i++)
        {
            v[i]={nums[i],i};
        }
        
        vector<int>count(n,0);
        mergesort(0,n-1,v,count);
        return count;
    }
};