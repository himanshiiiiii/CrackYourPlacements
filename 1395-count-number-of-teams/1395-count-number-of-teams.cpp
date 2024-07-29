class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int t = 0;
        
        for(int i = 1; i < n - 1; i++) {
            int csmallleft = 0, clargeleft = 0;
            int csmallright = 0, clargeright = 0;
            
            for(int j = 0; j < i; j++) {
                if(rating[i] < rating[j])
                    csmallleft++;
                if(rating[i] > rating[j])
                    clargeleft++;       
            }
            
            for(int j = i + 1; j < n; j++) {
                if(rating[i] < rating[j])
                    csmallright++;
                if(rating[i] > rating[j])
                    clargeright++;       
            }
            
            t += (csmallleft * clargeright) + (clargeleft * csmallright);
        }
        
        return t;
    }
};
