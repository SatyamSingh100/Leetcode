class Solution {
public:
    int f(vector<int>& a, int idx){
        int n = a.size();
        vector<int> dp(n,-1);
        if(idx == 0) return a[0];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int ntake = f(a,idx-1),take = -1e9;
        take = a[idx] + f(a,idx-2);
        dp[idx] = max(take,ntake);
        return max(take,ntake);
    }

    int rob(vector<int>& a) {
        int n=  a.size();
        vector<int> dp(n+1,0);
        dp[0] = 0; dp[1] = a[0];
        for(int i=2; i<=n; i++){
            int take = a[i-1] + dp[i-2];
            int ntake = dp[i-1];
            
            dp[i] = max(take,ntake);
        }
        return dp[n];
        // int ans = f(a,n-1);
        // return ans;
    }
};