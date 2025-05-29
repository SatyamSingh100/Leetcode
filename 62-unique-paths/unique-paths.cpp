class Solution {
public:
    int f(int r,int c){
        if(r==0 || c== 0) return 1;
        if(r<0 || c<0) return 0;
        int right =f(r,c-1);
        int down =f(r-1,c);
        return (right+down);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0; i<m; i++) dp[i][0] = 1;
        for(int j=0; j<n; j++) dp[0][j] = 1;

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                int right = dp[i][j-1];
                int down = dp[i-1][j];
                dp[i][j] = right + down;
            }
        }
        return dp[m-1][n-1];
        // dp[0][0] =1;
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(i==0 && j==0) dp[i][j] =1;
        //         else{
        //             int down =0,right=0;
        //             if(i>0)down = dp[i-1][j];
        //             if(j>0)right= dp[i][j-1];
        //             dp[i][j] = right+down;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];
    }
};