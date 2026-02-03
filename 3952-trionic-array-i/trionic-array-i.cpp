class Solution {
public:
    bool isTrionic(vector<int>& a) {
        int n = a.size();
        if(a[0] > a[1]) return false;
        int peak=0;
        for(int i=1; i<n; i++){
            if(a[i] == a[i-1]) return false;
            if(i == n-1) continue;
            if(a[i] > a[i-1] && a[i] > a[i+1]) peak++;
            else if(a[i] < a[i-1] && a[i] < a[i+1]) peak++;
        }
        if(peak == 2) return true;
        return false;
    }
};