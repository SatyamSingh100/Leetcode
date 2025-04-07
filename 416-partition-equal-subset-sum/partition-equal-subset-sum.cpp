class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0; i<n; i++) sum+=nums[i];
        if(sum%2!=0) return false;
        else{
            int tar = sum/2;
            vector<vector<bool>> dp(n,vector<bool>(tar+1,0));
            for(int i=0; i<n; i++) dp[i][0] =1;
            if(nums[0] <=tar) dp[0][nums[0]] =1;
            for(int i=1;i<n; i++){
                for(int j=1; j<=tar; j++){
                    bool npick= dp[i-1][j];
                    bool pick =0;
                    if(j>=nums[i]) pick = dp[i-1][j-nums[i]];
                    dp[i][j] = npick | pick;
                }
            }
            return dp[n-1][tar];
        }
    }
};