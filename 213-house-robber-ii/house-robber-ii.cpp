class Solution {
public:
    int f(vector<int>& a, int idx){
        int n = a.size();
        if(idx == 0) return a[0];
        if(idx < 0) return 0;
        vector<int> dp(n,-1);

        if(dp[idx] != -1) return dp[idx];
        int ntake = f(a,idx-1);
        int take = a[idx] + f(a,idx-2);

        dp[idx] = max(take,ntake);
        return max(take,ntake);
    }



    int tab(vector<int>& a){
        int n = a.size();
        vector<int> dp(n+1,0);
        dp[1] = a[0];
        for(int i=2; i<=n; i++){
            int take = a[i-1] + dp[i-2];
            int ntake = dp[i-1];

            dp[i] = max(ntake,take);
        }
        return dp[n];
    }
    int rob(vector<int>& a) {
        int n = a.size();
        if(n == 1) return a[0];
        vector<int> v1,v2;
        for(int i=0; i<n; i++){
            if(i!=0) v1.push_back(a[i]);
            if(i != n-1) v2.push_back(a[i]);
        }
        int ans1 = tab(v1), ans2 = tab(v2);
        int ans = max(ans1,ans2);
        return ans;





        //Recursive AND Memoization...
        // int ans1 = f(v1,v1.size()-1);
        // int ans2 = f(v2,v2.size()-1);
        // int ans = max(ans1,ans2);
        // return ans;
    }
};