class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size(),ans=1e9;
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][0] = a[0][0];
        for(int i=1; i<n; i++){
            for(int j=0; j<a[i].size(); j++){
                int up = 1e9, l_up = 1e9;
                if(j != a[i].size() - 1) up = a[i][j] + dp[i-1][j];
                if(j > 0) l_up = a[i][j] + dp[i-1][j-1];
                dp[i][j] = min(up,l_up);
            }
        }
        for(int j=0; j<a[n-1].size(); j++) ans = min(ans,dp[n-1][j]);
        return ans;



        // for(int j=0; j<n; j++) dp[n-1][j] = a[n-1][j];
        // for(int i=n-2; i>=0; i--){
        //     for(int j=0; j<=i; j++){
        //         dp[i][j] = a[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        //         // if(j > 0) dp[i][j] = min(a[i][j] + dp[i+1][j-1], dp[i][j]);
                
        //     }
        // }
        // return dp[0][0];
    }
};