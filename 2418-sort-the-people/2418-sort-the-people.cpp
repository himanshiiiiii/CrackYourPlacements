class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<string>ans;
        vector<pair<int,string>>person(n);
      
        for(int i=0;i<n;i++)
        {
          person[i]={heights[i],names[i]};  
        }
        sort(person.begin(),person.end());
    
        for(int i=n-1;i>=0;i--)
        {
            ans.push_back(person[i].second);
        }
        return ans;
    }
};