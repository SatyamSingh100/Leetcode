class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s = s + s;
        int cnt1 = 0, cnt2=0;
        for(int i=0; i<n; i++){
            int x1 = i%2, x2 =(i+1)%2;
            if(s[i] != x1 + '0') cnt1++;
            if(s[i] != x2 + '0') cnt2++;
        }
        int ans = min(cnt1,cnt2);
        for(int i=1; i<n; i++){
            if(s[i-1] != (i-1)%2 + '0') cnt1--;
            if(s[i+n-1] != (i+n-1)%2 + '0') cnt1++;

            if(s[i-1] != (i)%2 + '0') cnt2--;
            if(s[i+n-1] != (i+n)%2 + '0') cnt2++;

            ans = min(ans,min(cnt1,cnt2));
        }
        return ans;
    }
};