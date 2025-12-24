class Solution {
public:
    int f(vector<vector<int>>& a, int l, int end){
        int r = a.size() - 1,idx=a.size();
        while(l <= r){
            int mid = (l+r)/2;
            if(a[mid][0] > end){
                idx = mid; 
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return idx;
    }
    int maxTwoEvents(vector<vector<int>>& a) {
        int n = a.size(),ans=0;
        sort(a.begin(),a.end());

        vector<int> suff(n,0);
        suff[n-1] = a[n-1][2];
        for(int i=n-2; i>=0; i--) suff[i] = max(suff[i+1],a[i][2]);

        for(int i=0; i<n; i++){
            int idx = f(a,i+1,a[i][1]);
            if(idx == n) ans = max(ans,a[i][2]);
            else{
                ans = max(ans,a[i][2] + suff[idx]);
            }
        }
        return ans;
    }
};