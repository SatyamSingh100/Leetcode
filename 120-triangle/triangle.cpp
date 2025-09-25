class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0; j<n; j++) dp[n-1][j] = a[n-1][j];
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                dp[i][j] = a[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
                // if(j > 0) dp[i][j] = min(a[i][j] + dp[i+1][j-1], dp[i][j]);
                
            }
        }
        return dp[0][0];
    }
};