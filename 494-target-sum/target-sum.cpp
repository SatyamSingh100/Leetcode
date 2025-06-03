class Solution {
public:
    int f(int idx, int tar,vector<int>& a){
        // if(tar == 0) return 1;
        if(idx == 0){
            if(a[0] == 0 && tar ==0) return 2;
            if(tar == 0 || a[0] == tar) return 1;
            return 0;
        }
        int npick = f(idx-1,tar,a);
        int pick = 0;
        if(tar >= a[idx]) pick = f(idx-1,tar-a[idx],a);

        return pick + npick;
    }
    int findTargetSumWays(vector<int>& a, int target) {
        int n= a.size(),totsum=0;
        for(int i=0; i<n; i++) totsum += a[i];
        int tar = (totsum-target)/2;
        if(totsum< target || (totsum-target)% 2 != 0) return 0;

        int ans = f(a.size()-1,tar,a);
        return ans;


        // vector<vector<int>> dp(n,vector<int>(tar+1,0));

        // if(a[0] == 0) dp[0][0]=2;
        // else dp[0][0] =1;

        // if(a[0] != 0 && a[0] <= tar) dp[0][a[0]] =1;
        // for(int i=1; i<n; i++){
        //     for(int j=0; j<=tar; j++){
        //         int ntake = dp[i-1][j];
        //         int take =0;
        //         if(a[i] <= j) take = dp[i-1][j-a[i]];
        //         dp[i][j] = take+ntake;
        //     }
        // }
        // return dp[n-1][tar];
    }
};