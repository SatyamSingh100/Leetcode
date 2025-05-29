class Solution {
public:
    int f(int r,int c,vector<vector<int>>& a){
        int m = a.size(), n= a[0].size();
        if(r<0 || c<0) return 0;
        if(a[r][c] == 1) return 0;
        if(r==0 && c== 0) return 1;
        
        int right =f(r,c-1,a);
        int down =f(r-1,c,a);
        return (right+down);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m= a.size();
        int n=a[0].size();
        if(a[0][0] == 1 || a[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            if(a[i][0] == 1) break;
            dp[i][0] = 1;
        }
        for(int j=0; j<n; j++){
            if(a[0][j] == 1) break; 
            dp[0][j] = 1;
        }

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(a[i][j] == 1) dp[i][j] = 0;
        //     }
        // }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(a[i][j] != 1){
                int right = dp[i][j-1];
                int down = dp[i-1][j];
                dp[i][j] = right + down;
                }
            }
        }
        return dp[m-1][n-1];



        // int ans = f(m-1,n-1,a);
        // return ans;

        // if(a[0][0] == 1 || a[n-1][m-1]==1) return 0;
        // vector<vector<int>> dp(n,vector<int>(m,0));
        // dp[0][0] = 1;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(i==0 && j==0) dp[i][j] =1;
        //         else if(a[i][j] == 1) dp[i][j]=0;
        //         else{
        //             int right = 0,down=0;
        //             if(j>0) right += dp[i][j-1];
        //             if(i>0) down += dp[i-1][j];
        //             dp[i][j]= right + down;
        //         }
        //     }
        // }
        // return dp[n-1][m-1];
    }
};