class Solution {
public:
    string convertToTitle(int columnNumber) {
        
       int q=0;
        string ans="";
        while(columnNumber>26)
        {
          int val=(columnNumber-1)%26;
            ans=(char)(val+'A')+ans;
            columnNumber=(columnNumber-1)/26;
        }
        
         ans=(char)((columnNumber-1)+'A')+ans;
        
        return ans;
    }
};