class Solution {
public:
    int findLongestChain(vector<vector<int>>& a) {
        int n= a.size(),ans=1;
        sort(begin(a), end(a));
        vector<int> dp(n,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(a[j][1] < a[i][0]) dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans,dp[i]);
            }
        }
        return ans;
    }
};