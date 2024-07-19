
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int nums[], int n) 
    { 
        // Your code here
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            if(ele>=1 && ele<n)
            {
                int pos=ele-1;
                
                if(nums[pos]!=pos+1)
                {
                    swap(nums[pos],nums[i]);i--;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            return i+1;
        }
        return n+1;
    } 
};