class Solution {
public:
    int f(string& s, string& t,int idx1,int idx2){
        int n = s.size(),m=t.size();
        if(idx1 == n || idx2 == m) return 0;
        int pick = -1e9;
        if(s[idx1] == t[idx2]) pick = 1 + f(s,t,idx1+1, idx2+1);
        int npick = max(f(s,t,idx1,idx2+1) , f(s,t,idx1+1,idx2));
        return max(npick,pick);
    }

    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        // int ans = f(s,t,0,0);
        // return ans;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int pick = -1e9;
                if(s[i-1] == t[j-1]) pick = 1 + dp[i-1][j-1];
                int npick = max(dp[i-1][j] , dp[i][j-1]);
                dp[i][j] = max(npick,pick);
            }
        }
        return dp[n][m];
        // vector<vector<int>> dp(n+1,vector<int>((m+1),0));
        // for(int i=0; i<=n; i++){
        //     dp[i][0] = 0;
        // }
        // for(int j=0; j<=m; j++){
        //     dp[0][j] = 0;
        // }
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=m; j++){
        //         if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
        //         else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //     }
        // }
        // return dp[n][m];
    }
};