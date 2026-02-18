class Solution {
public:
    string toBin(int n){
        string ans = "";
        while(n > 0){
            if(n& 1) ans += '1';
            else ans += '0';
            n = n/2;
        }
        return ans;
    }
    bool hasAlternatingBits(int n) {
        string s = toBin(n);
        if(s.size() == 1) return true;
        for(int i=1; i<s.size(); i++){
            if(s[i] == s[i-1]) return false;
        }
        return true;
    }
};