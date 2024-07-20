class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),greater<int>());
     int n=nums.size();
        int prod1=nums[0]*nums[1]*nums[2];
        int prod2=nums[0]*nums[n-1]*nums[n-2];
        int prod3=nums[n-1]*nums[n-2]*nums[n-3];
        int prod4=nums[0]*nums[1]*nums[n-1];
        int prod=max(prod1,prod2);
        prod=max(prod,prod3);
        prod=max(prod,prod4);
        return prod;
    }
};