class Solution {
public:
    typedef unsigned long long ull;
    int solve(string& s, string& t, int n, int m){
        if(m == 0) return 1;
        if(n == 0) return 0;

        if(s[n-1] == t[m-1]) return solve(s,t,n-1,m-1) + solve(s,t,n-1,m);
        else return solve(s,t,n-1,m);

        return 0;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<ull>> dp(n+1, vector<ull>(m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int i=1; i<=m; i++) dp[0][i] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};