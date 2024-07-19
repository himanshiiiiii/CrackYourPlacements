class Solution {
public:
    string reverseWords(string s) {
        
        string ans="";
        
        for(int i=0;i<s.length();i++)
        {
            string word="";
            if(s[i]==' ')continue;
            while(s[i]!=' '&&i<s.length())
            {
                word=word+s[i];
                i++;
            }
            ans=word+" "+ans;
        }
        return ans.substr(0,ans.length()-1);
    }
};