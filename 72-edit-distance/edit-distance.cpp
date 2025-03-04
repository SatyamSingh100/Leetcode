class Solution {
public:
    int f(string& s, string& t, int idx1, int idx2){
        int n = s.size(),m=t.size();
        if(idx1 == n) return (m-idx2);
        if(idx2 == m) return (n-idx1);
        int pick = 1e9;
        if(s[idx1] == t[idx2]) pick = f(s,t,idx1+1, idx2+1);
        int npick =min((1+f(s,t,idx1+1,idx2+1)),min((1+f(s,t,idx1,idx2+1)),(1+f(s,t,idx1+1, idx2))));
        return min(npick,pick);
    }
    int minDistance(string s, string t) {
        int n = s.size(),m=t.size();
        // int ans = f(s,t,0,0);
        // return ans;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0; i<=n; i++){
            dp[i][0] = i;
        }
        for(int i=0; i<=m; i++){
            dp[0][i] = i;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int pick = 1e9;
                if(s[i-1] == t[j-1]) pick = dp[i-1][j-1];
                int npick = min((1 + dp[i-1][j-1]),min(1 + dp[i-1][j], 1 + dp[i][j-1]));
                dp[i][j] = min(pick,npick);
            }
        }
        return dp[n][m];
    }
};