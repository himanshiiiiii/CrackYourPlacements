//User function template for C++
class Solution{
public:	
	void reverseSubArray(int *arr, int n, int l, int r) {
	    // code here
	    reverse(arr+l-1,arr+r);
	}

};