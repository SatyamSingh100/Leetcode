class Solution {
public:
    bool f(char c){
        int a = c-48;
        if(a<0 || a>9) return false;
        return true;
    }
    string clearDigits(string s) {
        int n= s.size();
        string g ="";
        vector<int> v;
        vector<bool> a(n,0);
        for(int i=0; i<n; i++){
            if(f(s[i]) == true){
                v.push_back(i);
                a[i] =true;
            }
        }
        
        for(int i=1; i<n; i++){
            if(a[i] == true){
                int k=i-1;
                while(a[k] == true && k>=0){
                    k--;
                }
                a[k] = true;
            }
        }
        if(f(s[0]) == true) a[0] =true;
        for(int i=0; i<n; i++){
            if(a[i] == false) g += s[i];
        }
        return g;
    }
};