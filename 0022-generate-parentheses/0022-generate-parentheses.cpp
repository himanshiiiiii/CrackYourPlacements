class Solution {
public:
    bool isValid(string &curr)
    {
        int n=curr.length();
        stack<char>st;
        
        for(int i=0;i<n;i++)
        {
            if(!st.empty())
            {
                if(st.top()=='(' && curr[i]==')')
                    st.pop();
                else
                    st.push(curr[i]);
            }
            else
                
            st.push(curr[i]);
        }
        
        return st.empty();
    }
    void solve(vector<string>&res,string &curr,int n)
    {
        //means hr k liye 2 bracket ek open ek close
        if(curr.length()==2*n)
        {
            if(isValid(curr))
                res.push_back(curr);
            return ;
        }
        
        
        //ek baar open dalnge ek baar close
        curr.push_back('(');
         solve(res,curr,n);
             curr.pop_back();
          curr.push_back(')');
         solve(res,curr,n);
             curr.pop_back();
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>res;
    string curr="";
        solve(res,curr,n);
        
        return res;
        
    }
};