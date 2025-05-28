class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.size(),idx=-1;
        for(int i=n-1; i>=0; i--){
            int num = s[i] - '0';
            if(num % 2 != 0) {
                idx = i; break;
            }
        }
        string ans ="";
        if(idx != -1) ans = s.substr(0, idx+1);
        return ans;
    }
};