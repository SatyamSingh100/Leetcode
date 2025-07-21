class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans ="";
        if( n <= 2) return s;
        ans += s[0];
        ans += s[1];
        for(int i=2; i<n; i++){
            if(s[i] == s[i-1] && s[i-1] == s[i-2]) continue;
            ans += s[i];
        }
        return ans;
    }
};