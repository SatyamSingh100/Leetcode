class Solution {
public:
    bool check(string& a, string& b){
        int n = a.size(), m = b.size();
        if(m-n != 1) return false;
        int i=0,j=0;
        while(j<m){
            if(a[i] == b[j]){
                i++;
                j++;}
            else j++;
        }
        if(i!=n) return false;
        return true;
    }

    static bool comp(string& s1, string& s2){
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& a) {
        int n = a.size(),ans=1;
        sort(a.begin(), a.end(), comp);
        vector<int> dp(n,1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(check(a[j],a[i]) == true) dp[i] = max(dp[i] , dp[j] + 1);
                ans = max(ans,dp[i]);
            }
        }
        return ans;
    }
};