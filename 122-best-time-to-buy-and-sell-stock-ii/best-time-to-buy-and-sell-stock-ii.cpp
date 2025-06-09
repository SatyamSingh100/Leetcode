class Solution {
public:
    int maxProfit(vector<int>& a) {
        int sum =0;
        for(int i=1; i<a.size(); i++){
            int b=0;
            b += a[i]-a[i-1];
            if(b>0){
                sum += b;
            }
        }
        return sum;
        
    }
};