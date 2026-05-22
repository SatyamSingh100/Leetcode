class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n = a.size();
        k = k % n;
        if(n == 1) return;
        vector<int> b(n-k,0);
        for(int i=0; i<n-k; i++) b[i] = a[i];
        for(int i=0; i<n; i++){
            if(i < k) a[i] = a[(i+n-k)];
            else a[i] = b[i-k]; 
        }
    }
};