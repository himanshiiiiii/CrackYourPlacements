class Solution {
public:
    int nthUglyNumber(int n) {
        //p1,p2,p3 for multiple of 2,3,5 respectively
        int p1=0,p2=0,p3=0;
        vector<int>dp(n);
     
       dp[0]=1;

        for(int i=1;i<n;i++)
        {
            //We are taking from the predefined set only so that no different case occurs
            int twomul=dp[p1]*2;
            int threemul=dp[p2]*3;
            int fivemul=dp[p3]*5;
            
            dp[i]=min(twomul,min(threemul,fivemul));
             //becoz we have taken 1 multiple of2
            if(dp[i]==twomul)p1++;
            
             //becoz we have taken 1 multiple of3
            if(dp[i]==threemul)p2++;
             //becoz we have taken 1 multiple of5
            if(dp[i]==fivemul)p3++;
        }
        
        return dp[n-1];
    }
};