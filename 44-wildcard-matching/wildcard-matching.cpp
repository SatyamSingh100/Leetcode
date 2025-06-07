class Solution {
public:
    bool isAll(string s, int n){
        for(int i=1; i<=n; i++){
            if(s[i-1] != '*') return false;
        }
        return true;

    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,true));
        for(int i=1; i<=n; i++) dp[i][0] = false;
        for(int j=1; j<=m; j++){
            dp[0][j] = isAll(p,j);
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};