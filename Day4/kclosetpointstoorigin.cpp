class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n=points.size();
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;
        
        for(int i=0;i<n;i++)
        {
            double d=pow(points[i][0],2)+pow(points[i][1],2);
            double dist=sqrt(d);
            
            pq.push({dist,i});
        }
        vector<vector<int>>ans;
        for(int j=1;j<=k;j++)
        {
            vector<int>temp={points[pq.top().second][0],points[pq.top().second][1]};
            ans.push_back(temp);
            pq.pop();
        }
        
        return ans;
    }
};