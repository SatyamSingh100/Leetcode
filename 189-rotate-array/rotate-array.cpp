class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n = a.size();
        k = k % n;
        vector<int> temp(k);
        int idx =0;
        for(int i=n-k; i<n; i++) temp[idx++] = a[i];

        for(int i=n-k-1; i>=0; i--) a[i+k] = a[i];
        for(int i=0; i<k; i++) a[i] = temp[i];
    }
};