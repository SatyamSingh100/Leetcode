class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        vector<bool> a(2*n,false), b(2*n,false);
        s = s + s;
        string s1 = "", s2 ="";
        int cs1 = 0, cs2 = 1;
        for(int i=0; i<2*n -1; i++){
            s1 += (cs1 + '0'); s2 += (cs2 + '0');
            cs1 = !cs1; cs2 = !cs2;
        }

        for(int i=0; i<2*n-1; i++){
            if(s1[i] != s[i]) a[i] = true;
            if(s2[i] != s[i]) b[i] = true;
        }

        int cnt1=0,cnt2=0;
        for(int i=0; i<n; i++){
            if(a[i]) cnt1++;
            if(b[i]) cnt2++;
        }
        int ans = min(cnt1,cnt2);
        for(int i=1; i<n; i++){
            cnt1 -= a[i-1];  cnt1 += a[i+n-1];
            cnt2 -= b[i-1];  cnt2 += b[i+n-1];
            ans = min(ans,min(cnt1,cnt2));
        }
        return ans;
    }
};