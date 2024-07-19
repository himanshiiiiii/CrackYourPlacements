
class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        
      sort(arr.begin(),arr.end());
      x=abs(x);
      int l=0;
      int h=1;
 
     while(l<=h && h<arr.size())
     {
      int diff=arr[h]-arr[l];
      
      if(diff==x && l!=h)
      {
          return 1;
      }
   if(diff>x)l++;
      else
      h++;
     }
  
     return -1;
   
    }
};