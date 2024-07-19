//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        map<string,vector<string>>m;
        
        for(int i=0;i<string_list.size();i++)
        {
            string s=string_list[i];
            string t=s;
            sort(t.begin(),t.end());
            m[t].push_back(s);
        }
        
         vector<vector<string>>anagram;
        for(auto it:m)
        {
            anagram.push_back(it.second);
        }
        return anagram;
    }
};