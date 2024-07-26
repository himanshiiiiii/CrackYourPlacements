class Solution {
public:
    int evalRPN(vector<string>& s) {
        
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
        if(s[i] != "+" && s[i] != "-" && s[i] != "*" && s[i] != "/")
        {
            st.push(stoi(s[i]));
        }
            else
            {
                int ch1=st.top();st.pop();
                int ch2=st.top();st.pop();
                int res;
                 if (s[i] == "*")
                    res = ch2 * ch1;
                else if (s[i] == "/")
                    res = ch2 / ch1;
                else if (s[i] == "+")
                    res = ch2 + ch1;
                else if (s[i] == "-")
                    res = ch2 - ch1;

                st.push(res);
            }
        }
        return st.top();
    }
};