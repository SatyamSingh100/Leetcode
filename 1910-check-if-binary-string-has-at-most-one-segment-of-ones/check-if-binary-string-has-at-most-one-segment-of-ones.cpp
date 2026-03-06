class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int cnt =0;
        if(n == 0) return true;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]) continue;
            else{
                cnt++;
            }
        }
        if(cnt > 1) return false;
        return true;
    }
};