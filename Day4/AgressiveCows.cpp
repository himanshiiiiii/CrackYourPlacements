// User function Template for C++

class Solution {
public:

    bool isPossible(int diff,vector<int> &stalls,int cows,int n)
    {
        int c=1;
        int lastpos=stalls[0];
        for(int i=1;i<n;i++)
        {
            if(stalls[i]-lastpos>=diff)
            {
                c++;
                lastpos=stalls[i];
            }
            if(c>=cows)return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        
sort(stalls.begin(),stalls.end());
        // Write your code here
            if(k>n)return -1;
        int l=1;
        int h=stalls[stalls.size()-1]-stalls[0];
        int ans=0;
        
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(isPossible(mid,stalls,k,n))
            {
               ans=mid;
               l=mid+1;
               
            }
            else
             h=mid-1;
        }
        return ans;
    }
};