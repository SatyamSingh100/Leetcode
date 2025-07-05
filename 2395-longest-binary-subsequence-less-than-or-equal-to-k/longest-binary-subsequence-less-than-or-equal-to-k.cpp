class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size(),cnt=0,idx=0;
        for(int i=0; i<n; i++) if(s[i] == '0') cnt++;
        for(int i=n-1; i>=0; i--){
            if(idx >=30) break;
            if(s[i] == '1' && k>0){
                k = k - (1<<((n-1)-i));
                if(k>=0)cnt++;
            }
            idx++;
        }
        return cnt;
    }
};