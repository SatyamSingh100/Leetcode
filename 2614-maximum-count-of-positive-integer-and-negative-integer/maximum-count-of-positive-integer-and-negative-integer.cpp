class Solution {
public:
    int maximumCount(vector<int>& a) {
        int n =a.size(),p=0,q=0;
        for(int i=0; i<n; i++){
            if(a[i] > 0) p++;
            else if(a[i] < 0) q++;
        }
        return max(p,q);
    }
};