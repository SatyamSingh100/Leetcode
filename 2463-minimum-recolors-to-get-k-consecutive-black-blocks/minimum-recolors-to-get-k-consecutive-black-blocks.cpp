class Solution {
public:
    int f(string s){
        int n = s.size(),cnt=0;
        for(int i=0; i<n; i++){
            if(s[i] == 'W') cnt++;
        }
        return cnt;
    }
    int minimumRecolors(string s, int k) {
        int n= s.size(),ans=1e9;
        for(int i=0; i<=n-k; i++){
            string se = s.substr(i,k);
            int cnt = f(se);
            ans = min(ans,cnt);
        }
        return ans;
    }
};