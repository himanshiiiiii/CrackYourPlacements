class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        //first mapping ele of nums2 with their le=argest greater
        stack<int>st;
        map<int,int>m;
        int n=nums2.size();
        st.push(nums2[n-1]);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>=st.top())
            {
                st.pop();
            }
            
            int res=(st.empty())?-1:st.top();
            
            m[nums2[i]]=res;
            st.push(nums2[i]);
        }
        vector<int>res;
        for(int i=0;i<nums1.size();i++)
        {
            res.push_back(m[nums1[i]]);
        }
        return res;
    }
};