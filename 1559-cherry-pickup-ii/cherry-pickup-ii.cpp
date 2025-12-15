class Solution {
public:
    int f(int i, int j1,int j2, vector<vector<int>>& a, vector<vector<vector<int>>>& dp){
        int n = a.size(), m = a[0].size(),num=0;
        if(j1 < 0 || j1 > m-1 || j2 < 0 || j2 > m-1) return 0;
        if(i == n-1){
            if(j1 == j2) return a[i][j1];
            else return a[i][j1] + a[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int ans = 0;
                if(j1 == j2) ans = a[i][j1];
                else ans = a[i][j1] + a[i][j2];
                ans += f(i+1,j1 + dj1, j2 + dj2,a,dp);
                num = max(num,ans);
            }
        }
        dp[i][j1][j2] = num;
        return num;
    }
    int cherryPickup(vector<vector<int>>& a) {
        int n= a.size(), m = a[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(m,-1)));
        int ans = f(0,0,m-1,a,dp);
        return ans;
    }
};