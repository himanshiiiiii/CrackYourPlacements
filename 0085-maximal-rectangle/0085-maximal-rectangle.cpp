class Solution {
public:
    vector<int> nextsmaller(vector<int>&v , int n){
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevsmaller(vector<int>&v , int n){
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangle(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        vector<int> next(n), prev(n);
        next = nextsmaller(heights, n);
        prev = prevsmaller(heights, n);
        for(int i=0;i<n;i++){
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            int area = l * b;
            ans = max(ans, area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>histo(matrix[0].size(),0);
        int maxi=INT_MIN;
         for(int i=0;i<matrix.size();i++)
        {
             for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1')
                    histo[j]++;
                else
                    histo[j]=0;
            }
                maxi=max(maxi,largestRectangle(histo));
        }
     
        
        return maxi;
            
    }
};