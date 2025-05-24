class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n= a.size(),sum = 0;
        if(n == 1) return 0;
        int i=0,j=1;
        while(j<n && (j-i)>=1){
            sum = max(sum,a[j]-a[i]);
            if(a[j] - a[i] < 0){
                i = j;
            }
            j++;
        }
        return sum;
        
        
    }
};