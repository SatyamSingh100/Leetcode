class Solution {
public:
    int strStr(string s, string tar) {
        int n = s.size(), m= tar.size();
        if(n < m) return -1;
        else if(n == m){
            if(s == tar) return 0;
            else return -1; 
        } 
        for(int i=0; i<=n-m; i++){
            string st = s.substr(i,m);
            if(st == tar){
                return i;
            }
        }
        return -1;
    }
};