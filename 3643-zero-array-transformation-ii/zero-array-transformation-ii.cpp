class Solution {
public:
bool f(vector<int>& a, vector<vector<int>>& q, int k){
    int n = a.size();
    vector<int> ans(n,0);
    for(int i=0; i<=k; i++){
        int l = q[i][0], r = q[i][1], val = q[i][2];
        ans[l] += val;
        if((r+1) < n) ans[r+1] -= val;
    }
    for(int i=1; i<n; i++){
        ans[i] += ans[i-1];
    }
    for(int i=0; i<n; i++){
        if(a[i] > ans[i]) return false;
    }
    return true;
}
bool check(vector<int>& a){
    for(int i=0; i<a.size(); i++){
        if(a[i] != 0) return false;
    }
    return true;
}
    int minZeroArray(vector<int>& a, vector<vector<int>>& q) {
        int n = a.size();
        int l=0,r=q.size()-1,ans=1e9;
        if(check(a)) return 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(f(a,q,mid)) r = mid-1, ans= min(ans,mid);
            else l = mid+1;
        }
        if(ans != 1e9) return ans+1; 
        return -1;
    }
};