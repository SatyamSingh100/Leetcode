class Solution {
public:
    int f(vector<vector<int>>& a, int i, int j){
        if(i == 0 && j == 0) return a[0][0];
        if(i< 0 || j<0) return 1e9;
        int left = a[i][j] + f(a,i,j-1);
        int top = a[i][j] + f(a,i-1,j);
        return min(top,left);
    }

    int minPathSum(vector<vector<int>>& a) {
        int m=  a.size();
        int n= a[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = a[0][0];

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j==0) dp[i][j] = a[i][j];
                else{
                    int right = 1e9,down=1e9;
                if(j>0) right = a[i][j] + dp[i][j-1];
                if(i>0) down = a[i][j] + dp[i-1][j];
                dp[i][j] = min(right,down);
                }
            }
        }
        return dp[m-1][n-1];




        // int ans = f(a,m-1,n-1);
        // return ans;



        // vector<vector<int>> dp(n,vector<int>(m,0));
        // dp[0][0] = a[0][0];
        // for(int i=0;i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(i==0 && j==0) dp[i][j] = a[i][j];
        //         else {
        //             int right = a[i][j],down=a[i][j];
        //             if(i>0) down += dp[i-1][j];
        //             else down += 1e9;
        //             if(j>0) right+= dp[i][j-1];
        //             else right += 1e9;
        //             dp[i][j] = min(down,right);
        //         }
        //     }
        // }
        // return dp[n-1][m-1];
    }
};