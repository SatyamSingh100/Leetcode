class Solution {
public:
    double champagneTower(int p, int row, int col) {
        vector<vector<double>> dp(101,vector<double>(101,0.0000));
        dp[0][0] = (double)p;
        for(int i=1; i<=100; i++){
            for(int j=0; j<=i; j++){
                if(j != 0 && dp[i-1][j-1] > 1.0000) dp[i][j] += (dp[i-1][j-1] - 1)/2;
                if(dp[i-1][j] > 1.0000) dp[i][j] += (dp[i-1][j] - 1)/2;
            }
        }
        if(dp[row][col] > 1.0000) return 1.0000;
        return dp[row][col];
    }
};