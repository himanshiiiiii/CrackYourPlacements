// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    bool isPossible(int pages,int m,int arr[],int n)
    {
        
        int studentcount=1;
        int pagescount=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>pages)return false;
            if(pagescount+arr[i]<=pages)
            {
                pagescount+=arr[i];
            }
            else
            {
                studentcount++;
                  if(studentcount>m)return false;
                pagescount=arr[i];
            }
            
          
        }
        return true;
    }
    long long findPages(int n, int arr[], int m) {
        // code here
        if(n<m)return -1;
        int l=0;
        int h=0;
        for(int i=0;i<n;i++)
        {
            h+=arr[i];
        }
      long long ans=0;
        while(l<=h)
        {
            
            int mid=l+(h-l)/2;
            
            if(isPossible(mid,m,arr,n))
            {
                ans=mid;
                 h=mid-1;
            }
            else
            {
               l=mid+1;
            }
        }
        return ans;
    }
};