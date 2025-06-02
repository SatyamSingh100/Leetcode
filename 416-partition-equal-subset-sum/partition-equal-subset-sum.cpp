class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n = a.size(),sum=0,k=0;
        for(int i=0; i<n; i++) sum += a[i];
        if(sum & 1) return false;
        else{
            k = sum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));
        for(int i=0; i<n; i++) dp[i][0] = true;
        if(k >= a[0]) dp[0][a[0]] = true;
        for(int i=1; i<n; i++){
            for(int j=1; j<=k; j++){
                bool ntake = dp[i-1][j];
                bool take = false;
                if(j >= a[i]) take = dp[i-1][j-a[i]];

                dp[i][j] = ntake | take;
            }
        }
        return dp[n-1][k];
        }
        return false;
    }
};