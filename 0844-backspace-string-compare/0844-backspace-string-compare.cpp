class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        
        stack<char>st;
        for(int i=0;i<n1;i++)
        {
            if(!st.empty())
            {
                if(s[i]=='#')
                    st.pop();
                else
                    st.push(s[i]);
            }
         else if(s[i]!='#')
                st.push(s[i]);
        }
        s="";
        while(!st.empty())
        {
            s.push_back(st.top());
            st.pop();
        }
      for(int i=0;i<n2;i++)
        {
            if(!st.empty())
            {
                if(t[i]=='#')
                    st.pop();
                else
                    st.push(t[i]);
            }
            else if(t[i]!='#')
                st.push(t[i]);
        }
        t="";
        while(!st.empty())
        {
            t.push_back(st.top());
            st.pop();
        }
      cout<<s<<" "<<t;
        return (s==t);
    }
};