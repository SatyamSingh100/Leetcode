class Solution {
public:
    bool check(vector<int> a, int mid,int k,int m){
        int n = a.size(),cnt=0,bouq=0;
        for(int i=0; i<n; i++){
            if(bouq == k){
                cnt++; bouq = 0;
            }
            if(a[i] <= mid) bouq++;
            else bouq=0;
        }
        if(bouq == k) cnt++;
        if(cnt >= m) return true;
        return false; 
    }
    int minDays(vector<int>& a, int m, int k) {
        int l =1e9, r=0, n = a.size(),ans=-1;
        long long num = m;
        num = num * k;
        if(num > n) return ans;
        for(int i=0; i<n; i++){
            l = min(l,a[i]);
            r = max(r,a[i]);
        }
        while(l <= r){
            int mid = (l + r)/2;
            if(check(a,mid,k,m)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};