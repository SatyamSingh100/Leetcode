class Solution {
public:
    int f(string s,string t) {
        int n = s.size(),m=t.size();
        // string t = s;
        // reverse(begin(t),end(t));
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int minDistance(string s, string t) {
        int n = s.size(), m= t.size();
        int ans = f(s,t);
        return (n-ans) + (m-ans);
    }
};