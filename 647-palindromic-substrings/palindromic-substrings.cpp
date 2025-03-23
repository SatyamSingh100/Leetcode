class Solution {
public:
    bool check(string s){
        int n= s.size();
        if(n==1) return true;
        int i=0,j=n-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n= s.size(),cnt=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string str = s.substr(i,j-i+1);
                if(check(str) == true) cnt++;
            }
        }
        return cnt;
    }
};