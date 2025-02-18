class Solution {
public:
    int minimumPushes(string a) {
        int n = a.size();
        // unordered_map<char,int> m;
        // for(int i=0; i<n; i++){
        //     if(m.find(a[i]) == m.end()) m[a[i]] =1;
        //     else m[a[i]]++;
        // }
        if(n<9) return n;
        else if(n>=9 && n<=16) return 8 + (n-8)*2;
        else if(n>16 && n<=24) return 24 + (n-16)*3;
        else return 48 + (n-24)*4;
        return -1;
    }
};