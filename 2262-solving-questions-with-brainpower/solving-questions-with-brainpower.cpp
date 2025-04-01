class Solution {
public:
    int f(int idx,vector<vector<int>>& a){
        int n = a.size();
        if(idx >= n) return 0;
        int ntake = f(idx +1, a);
        int skip = a[idx][1] +1;
        int take = a[idx][0] + f(idx + skip,a);
        return max(take,ntake);
    }
    long long mostPoints(vector<vector<int>>& a) {
        // int ans = f(0,a);
        // return ans;
        
        int n= a.size();
        if(n ==1) return a[0][0];
        vector<long long> dp(200001,0);
        // dp[0] =0;
        for(int i=n-1; i>=0; i--){
            long long ntake = dp[i+1];
            long long skip  = a[i][1] +1;
            long long take = a[i][0] + dp[i+ skip];
            dp[i] = max(take,ntake);
        }
        return dp[0];
    }
};