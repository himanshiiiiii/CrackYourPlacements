class Solution {
public:
   
    void solve(vector<string>&res,string &curr,int n,int open,int close)
    {
        //means hr k liye 2 bracket ek open ek close
        if(curr.length()==2*n)
        {
                res.push_back(curr);
            return ;
        }
        
        
        //ek baar open dalnge ek baar close
        if(open<n)
        {
        curr.push_back('(');
            open+1;
       solve(res,curr,n,open+1,close);
            open-1;
             curr.pop_back();
    }
         if(close<open)
         {
          curr.push_back(')');
         close+1;
         solve(res,curr,n,open,close+1);
             close-1;
             curr.pop_back();
     
         }       
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>res;
    string curr="";
        int open=0,close=0;
        solve(res,curr,n,open,close);
        
        return res;
        
    }
};