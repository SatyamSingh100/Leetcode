class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        string ans ="";
        if(n == 1) return s[0];
        int j = 1e9;
        for(int i=0; i<n; i++){
            int size = s[i].size();
            j = min(j,size);
        }
        for(int i=0; i<j; i++){
            bool check = true;
            for(int k=1; k<n; k++){
                if(s[k][i] != s[k-1][i]) check = false;
            }
            if(check) ans += s[0][i];
            else break;
        }
        return ans;
    }
};