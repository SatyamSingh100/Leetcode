class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        if(n == 1) return 0;
        int cost = a[0],ans=0;
        for(int i=1; i<n; i++){
            ans = max(ans,a[i]-cost);
            if(a[i] < cost) cost = a[i];
        }
        ans = max(ans,0);
        return ans;
    }
};