class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n=cardPoints.size();
        int leftsum=0;
        
        
        for(int i=0;i<=k-1;i++)
        {
            leftsum+=cardPoints[i];
        }
        int maxi=leftsum;
        int right=n-1;
        int rightsum=0;
        
        for(int j=k-1;j>=0;j--)
        {
            leftsum-=cardPoints[j];
            rightsum+=cardPoints[right];
            
            maxi=max(maxi,leftsum+rightsum);
            right--;
        }
        
        return maxi;
    }
};