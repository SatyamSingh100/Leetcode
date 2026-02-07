class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(),ans=1e9;
        vector<int> a(n+2,0),b(n+2,0);
        int cntb=0,cnta=0;
        b[0] = 0;
        for(int i=0; i<n; i++){
            b[i+1] = cntb;
            if(s[i] == 'b') cntb++;
        }
        b[n+1] = cntb;  a[n+1] = 0;
        for(int i=n; i>=0; i--){
            a[i+1] = cnta;
            if(s[i] == 'a') cnta++;
        }
        a[0] = cnta;
        for(int i=0; i<n+2; i++){
            int num = a[i] + b[i];
            ans = min(ans,num);
        }
        if(ans == 1e9) return 0;
        return ans;
    }
};