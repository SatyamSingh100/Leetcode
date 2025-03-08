class Solution {
public:
    bool f(string s){
        int n= s.size();
        int i=0,j=n-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string t = "";
        for(int i=0; i<s.size(); i++){
            if((s[i] >= 48 && s[i] <=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
                t += s[i];
            }
        }
        int n=  t.size();
        for(int i=0; i<n; i++){
            if(t[i] >=65 && t[i]<=90){
                t[i] = t[i] + 32;
            }
        }
        bool ans = f(t);
        return ans;
        
    }
};