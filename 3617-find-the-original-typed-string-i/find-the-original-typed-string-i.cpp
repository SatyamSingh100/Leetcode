class Solution {
public:
    int possibleStringCount(string s) {
        int n = s.size();
        int cnt = 1, ans =1;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]) cnt++;
            else {
                ans += cnt - 1; cnt=1;
            }
        }
        ans += cnt - 1;
        return ans;
    }
};