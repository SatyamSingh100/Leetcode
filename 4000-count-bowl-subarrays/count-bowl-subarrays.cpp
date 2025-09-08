class Solution {
public:
    long long bowlSubarrays(vector<int>& a) {
        int n = a.size();
        vector<int> pge(n,-1);
        vector<int> nge(n,-1);
        int maxi = a[0];
        for(int i=1; i<n-1; i++){
            if(maxi > a[i]) pge[i] = maxi;
            maxi = max(maxi,a[i]);
        }
        maxi = a[n-1];
        for(int i=n-2; i>=1; i--){
            if(maxi > a[i]) nge[i] = maxi;
            maxi = max(maxi,a[i]);
        }
        int cnt=0;
        for(int i=1; i<n-1; i++){
            if(pge[i] != -1 && nge[i] != -1) cnt++;
        }
        return cnt;
    }
};