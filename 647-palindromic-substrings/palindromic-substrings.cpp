class Solution {
public:
    bool check(string s){
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            else{
                i++; j--;
            }
        }
        return true;
    } 
    int countSubstrings(string s) {
        int n = s.size(),cnt=0;
        int i = 0,j=n-1;
        for(int i=0; i<n;i++){
            for(int j=i; j<n; j++){
                int len = (j-i+1);
                string st = s.substr(i,len);
                if(check(st) == true) cnt++; 
            }
        }
        return cnt;
    }
};