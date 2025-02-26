class Solution {
public:
    int rob(vector<int>& a) {
        int n=  a.size();
        vector<int> dp(n,0);
        dp[0] = a[0];
        if(n>1) dp[1] = max(a[1],a[0]);
        for(int i=2; i<n; i++){
            int take = a[i] + dp[i-2];
            int ntake = dp[i-1];
            dp[i] = max(take,ntake);
        }
        return dp[n-1];
    }
};