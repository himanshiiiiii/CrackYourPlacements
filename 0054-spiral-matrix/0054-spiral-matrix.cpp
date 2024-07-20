class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int>ans;
        int r=matrix.size();
        int c=matrix[0].size();
        int srow=0;
        int erow=r-1;
        int scol=0;
        int ecol=c-1;
        int count=0;
        int total=r*c;
        
        while(total>count)
        {
        
            for(int j=scol;count<total&&j<=ecol;j++)
            {
                ans.push_back(matrix[srow][j]);
                count++;
            }
            srow++;
            
            for(int i=srow;count<total&&i<=erow;i++)
            {
                ans.push_back(matrix[i][ecol]);
                count++;
            }
            ecol--;
            
            for(int j=ecol;count<total&&j>=scol;j--)
            {
                ans.push_back(matrix[erow][j]);
                count++;
            }
            erow--;
            
             for(int i=erow;count<total&&i>=srow;i--)
            {
                ans.push_back(matrix[i][scol]);
                count++;
            }
           scol++;
        }
        return ans;
        
    }
};