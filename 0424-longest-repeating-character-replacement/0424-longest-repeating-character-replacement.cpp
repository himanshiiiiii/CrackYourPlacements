class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int l=0;
        int r=0;
        int n=s.length();
        int maxi=0;
          int maxcount = 0;
        vector<int>m(26,0);
        while(r<n)
        {
            m[s[r]-'A']++;
            
            //chars to be updated
          maxcount=max(maxcount,m[s[r]-'A']);
            
            if((r-l+1)-maxcount>k)
            {
               m[s[l]-'A']--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        
        return maxi;
    }
};