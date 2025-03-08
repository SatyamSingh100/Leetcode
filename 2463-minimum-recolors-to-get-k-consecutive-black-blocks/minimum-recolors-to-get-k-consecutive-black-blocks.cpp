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
        int n= s.size(),ans=1e9,cnt=0;
        int i = 0, j=0;
        while(i<n && j<n){
            if(s[j] == 'W') cnt++;
            if(j-i+1 == k){
                ans = min(ans,cnt);
                if(ans == 0) return ans;
                if(s[i] == 'W') cnt--;
                i++;
            }
            j++;
        }
        return ans;
    }
};