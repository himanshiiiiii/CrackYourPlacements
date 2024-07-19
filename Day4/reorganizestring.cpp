class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        if(n==1)return s;
        map<char,int>m;
            priority_queue<pair<int,char>>pq;
        
        for(auto ch:s)
        {
            m[ch]++;
            
            if(m[ch]>(n+1)/2)return "";
        }
        
        for(auto it:m)
        {
            pq.push({it.second,it.first});
        }
        
        string res="";
        while(pq.size()>=2)
        {
          auto p1 =pq.top();
            pq.pop();
            auto p2=pq.top();
            pq.pop();
                
            res+=p1.second;p1.first--;
            res+=p2.second;p2.first--;
            
           if(p1.first>0)
           {
               pq.push({p1.first,p1.second});
           }
            if(p2.first>0)
           {
               pq.push({p2.first,p2.second});
           }
           
        }
        
        if(!pq.empty())
            res+=pq.top().second;
        return res;
    }
};