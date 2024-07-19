class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        if(h+1==1)return 0;
        while(l<h)
        {
            int mid=l+(h-l)/2;
           
            
            //first half sorted
            if(nums[mid]<nums[mid+1])
            {
                l=mid+1;
            }
            else
            {
                h=mid;        
            }
        }
        return h;
    }
};