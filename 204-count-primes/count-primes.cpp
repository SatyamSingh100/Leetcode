class Solution {
public:
    int countPrimes(int n) {
        vector<bool> a(n+1,true);
        a[0] = false; a[1] = false;
        for(int i=0; i<n; i++){
            if(a[i] == true){
                for(int j=2*i; j<n; j += i){
                    a[j] = false;
                }
            }
        }
        int cnt =0;
        for(int i=0; i<n; i++){
            if(a[i] == true) cnt++;
        }
        return cnt;
    }
};