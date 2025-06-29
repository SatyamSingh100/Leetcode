class Solution {
public:
    int f(int idx, int tar, vector<int> a){
        int n= a.size();
        if(idx == 0){
            if(tar%a[idx] == 0) return tar/a[idx];
            else return 1e9;
        }
        int npick = f(idx-1, tar,a);
        int pick= 1e9;
        if(a[idx] <= tar) pick = 1+ f(idx,tar-a[idx],a);
        return min(pick,npick);
    }
    int coinChange(vector<int>& a, int tar) {
        // int ans = f(a.size()-1, tar,a);
        // if(ans==1e9) return -1;
        // return ans;
        // // long long n= a.size();
        // // vector<vector<long long>> dp(n,vector<long long>(tar+1,1e9));
        // // for(int i=0; i<=tar; i++){
        // //     if(i%a[0] == 0) dp[0][i] = i/a[0];
        // // }
        // // for(int i=1; i<n;i++){
        // //     for(int j=0; j<=tar; j++){
        // //         long long npick = dp[i-1][j];
        // //         long long pick = 1e9;
        // //         if(a[i] <= j) pick = 1 + dp[i][j-a[i]];
        // //         dp[i][j] = min(pick,npick);
        // //     }
        // // }
        // // if(dp[n-1][tar] == 1e9) return -1;
        // // return dp[n-1][tar];
        int n = a.size();
        vector<vector<int>> dp(n+1,vector<int>(tar+1,1e9));
	
	for(int i=0; i<=n; i++) dp[i][0] = 0;
	for(int i=0; i<=tar; i++){
		if(i % a[0] == 0) dp[0][i] = i / a[0];
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=tar; j++){
			dp[i][j] = dp[i-1][j];
			if(j >= a[i-1]) dp[i][j] = min(dp[i][j],1+ dp[i][j-a[i-1]]);
		}
	}
	if(dp[n][tar] == 1e9) return -1;
    return dp[n][tar];
    }
};