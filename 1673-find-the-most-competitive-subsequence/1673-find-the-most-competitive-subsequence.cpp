class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>st;
        
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty()&& st.top()>nums[i] && st.size()+nums.size()-i>k)
                st.pop();
            
            if(st.size()<k)
            st.push(nums[i]);
            
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};