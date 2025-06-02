class Solution {
public:
int f(int idx, int tar, vector<int> a){
        int n= a.size();
        if(tar == 0) return 1;
        if(idx == 0){
            if(tar%a[idx] == 0) return 1;
            else return 0;
        }
        int npick = f(idx-1, tar,a);
        int pick= 0;
        if(a[idx] <= tar) pick = f(idx,tar-a[idx],a);
        return pick + npick;
    }
    int change(int tar, vector<int>& a) {
        // int ans = f(a.size()-1, tar,a);
        // return ans;
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(tar+1,0));
        for(int i=0; i<n; i++) dp[i][0] = 1;
        for(int i=0; i<=tar; i++){
            if(i % a[0] == 0) dp[0][i] = 1;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<=tar; j++){
                 long npick = dp[i-1][j];
                 long pick = 0;
                if(j >= a[i]) pick = dp[i][j-a[i]];
                dp[i][j] = pick;
                dp[i][j] += npick;
            }
        }
        return dp[n-1][tar];
    }
};