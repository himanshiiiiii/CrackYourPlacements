class Solution {
public:
    vector<int>prevsmallele(vector<int>& arr,int n)
    {
         vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
        while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
            int val=(st.empty())?-1:st.top();
            ans[i]=val;
            st.push(i);
         }
        return ans;
    }
    vector<int>nextsmallele(vector<int>& arr,int n)
    {
         vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
        while(!st.empty() && arr[st.top()]>arr[i])
            st.pop();
            int val=(st.empty())?n:st.top();
            ans[i]=val;
            st.push(i);
         }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int sum=0;
        int mod=1000000007;
     int n=arr.size();
     vector<int>nse=nextsmallele(arr,n);
      vector<int>pse=prevsmallele(arr,n);  
        for(int i=0;i<n;i++)
        {
           int leftsmall=i-pse[i];
            int rightsmall=nse[i]-i;
          sum = (sum + (leftsmall * rightsmall % mod)*1LL * arr[i] % mod) % mod;
        }
        return sum;
    }
};