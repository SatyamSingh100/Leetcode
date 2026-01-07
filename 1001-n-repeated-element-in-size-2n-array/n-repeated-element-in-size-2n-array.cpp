class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
        int n = a.size();
        for(int i=0; i<n-1; i++){
            if(i != n-2) if(a[i] == a[i+1] || a[i] == a[i+2]) return a[i];
            if(i != 0){
                if(a[i] == a[i-1] || a[i] == a[i+1]) return a[i];
            }
        }
        if(a[0] == a[n-1]) return a[0];
        return -1;
    }
};