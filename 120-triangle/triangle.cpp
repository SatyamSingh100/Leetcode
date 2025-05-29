class Solution {
public:
    int f(vector<vector<int>>& a, int i, int j){
        int n = a.size();
        if(i == n-1) return a[i][j];
        
        int down = a[i][j] + f(a,i+1,j);
        int dright = a[i][j] + f(a,i+1,j+1);

        return min(down,dright);
    }
    int minimumTotal(vector<vector<int>>& a) {
        int n=  a.size();
        int m = a[n-1].size();

        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int j=0; j<m; j++) dp[n-1][j] = a[n-1][j];

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                int up = a[i][j] + dp[i+1][j];
                int left = a[i][j] + dp[i+1][j+1];

                dp[i][j] = min(up,left);
            }
        }
        return dp[0][0];
        // int ans = f(a,0,0);
        // return ans;


        // vector<vector<int>> dp(n,vector<int>(n,0));
        // for(int i=0; i<m; i++){
        //     dp[n-1][i] = a[n-1][i];
        // }
        // for(int i=n-2; i>=0; i--){
        //     for(int j=0; j<=i; j++){
        //         int ae = a[i][j] + dp[i+1][j];
        //         int b= a[i][j] + dp[i+1][j+1];
        //         dp[i][j] = min(ae,b);
        //     }
        // }
        // return dp[0][0];
    }
};