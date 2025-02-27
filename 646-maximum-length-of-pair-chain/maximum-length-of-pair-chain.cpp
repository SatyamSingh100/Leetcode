class Solution {
public:

// This problem is exactly similar to LIS(longest inc subsequence), only thing ie changing here is that we can choose pair in any order. So, first sort the vector; & then simply run the LIS Loop;
// LIS ----> For Bottom-Up we dont copy the recursion code here but what we do is:   For every 'i' we take 'j' from 0-(i-1) and get the larget possible subsequence for every 'i' and then we store it in a "ans" variable...


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