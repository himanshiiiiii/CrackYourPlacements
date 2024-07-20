class Solution {
public:
    string addBinary(string a, string b) {
        
        int n1 = a.length();
        int n2 = b.length();
        int p1=n1-1,p2=n2-1;
        int carry=0;
        string res="";
        while(p1>=0 && p2>=0)
        {
            int val=(a[p1]-'0')+(b[p2]-'0')+carry;
            p1--;p2--;
            int d=val%2;
            carry=val/2;
            res=to_string(d)+res;  
        }
        while(p1>=0 )
        {
            int val=(a[p1]-'0')+carry;
            p1--;
            int d=val%2;
            carry=val/2;
            res=to_string(d)+res;  
        }
        while(p2>=0)
        {
            int val=(b[p2]-'0')+carry;
            p2--;
            int d=val%2;
            carry=val/2;
            res=to_string(d)+res;  
        }
        while(carry!=0)
        {
            res=to_string(carry)+res;
            carry--;
        }
        
        return res;
    }
};