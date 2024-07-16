class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<int>mini(n);
        mini[0]=prices[0];
        for(int i=1;i<n;i++)
        {
            mini[i]=min(mini[i-1],prices[i]);
        }
        int profit=0;
        for(int i=0;i<n;i++)
        {
            profit=max(profit,prices[i]-mini[i]);
        }
        return profit;
    }
};